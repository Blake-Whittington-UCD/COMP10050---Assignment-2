#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


int getSize(piece *top){

    if (top == NULL) //This is the base case
        return 0;

    return 1 + getSize(top->next); //returns 1 + the size of the stack
}

void extraPieces(int a, int b, square board[BOARD_SIZE][BOARD_SIZE], struct player players  ){
piece *inStack = board[a][b].stack, *outStack;
            int i = 0;
            while (++i<5)
                inStack = inStack->next; //Searches for extra pieces until there are no more extra pieces left
            outStack = inStack->next;
            while (outStack != NULL)
            {
                piece *toRemove = outStack;
//update player's pile

                //If the color of the player and the color of the extra piece are the same, the piece is marked as capable of being reused later
                if((players.player_color == GREEN && outStack->p_color == GREEN) || (players.player_color == RED && outStack->p_color == RED))
                    players.own_pieces_captured++;
                //If the colors don't match up between the player and the extra piece, then the piece is counted as leaving the game permanently
                else if((players.player_color == GREEN && outStack->p_color == RED) || (players.player_color == RED && outStack->p_color == GREEN))
                    players.captured_pieces++;

                outStack = outStack->next;
                free(toRemove); //Releases the extra piece

            }
                inStack->next = NULL;
}

void moveStack(int position1, int position2, int a, int b, struct player players, square board[BOARD_SIZE][BOARD_SIZE]) {

    piece *top_of_current = board[position1][position2].stack; //Assigning the various boards with their respective titles

    piece *top_of_destination = board[a][b].stack;

    piece *current = top_of_current;

//If there is nothing on the section of the board that you are trying to place a stack, this transfers the stack from one section to another
    if (board[a][b].type == VALID && board[a][b].stack == NULL) {

        board[a][b].stack = board[position1][position2].stack;
        board[a][b].num_pieces = board[position1][position2].num_pieces;

        board[position1][position2].stack = NULL;
    }

    else {
        while (current->next != NULL) { //Takes the stack you want to move and finds the bottom of it

            current = current->next;

        }
        current->next = top_of_destination; //Takes the previously empty next piece of the current stack and "puts it on top" of the destination stack


        board[a][b].stack = top_of_current;
        //The new stack that has been created from both stacks is put on the grounds of the old stack


        board[position1][position2].stack = NULL; //The location of the old stack is now vacant so anything still there is dismissed



        board[a][b].num_pieces += board[position1][position2].num_pieces; //This combines the number of pieces from both stacks

        if (board[a][b].num_pieces > 5) {

            extraPieces(a, b, board, players);

        }

        board[position1][position2].num_pieces = 0; //Resetting the old location's number of pieces after the stack has moved


    }
}

void userMove(struct player players, square board[BOARD_SIZE][BOARD_SIZE]) {

    int position1 = 0, position2 = 0, x = 0, y = 0, moveDist = 0;
    char player_piece_decision;
    bool legalMove = false;

    printf("It's %s's turn\nPick a %s space\n", players.name, players.player_color == RED ? "RED"
                                                                                          : "GREEN"); //Tells the user who's turn it is and reminds them of their color
    //Gets the coordinates of the square to be moved
    while (!legalMove) { //The user isn't allowed to leave this while loop until they have picked a column and row to move that is considered a legitimate location

        if (players.own_pieces_captured >= 1) {
            printf("Would you like to use one of your stored pieces?\nIf so, please input the letter y, otherwise input the letter n: \n");
            scanf("%c", &player_piece_decision);

            while (player_piece_decision != 'y' && player_piece_decision != 'n' && player_piece_decision != 'Y' &&
                   player_piece_decision != 'N') {
                printf("Please input either a y or an n based on if you want to use a stored piece. \n");
                scanf("%c", &player_piece_decision);
            }
            if (player_piece_decision == 'y' || player_piece_decision == 'Y') {
                printf("Which column would you like to put your piece on?\n");
                scanf("%d", &y);
                printf("Which row would you like to put your piece on?\n");
                scanf("%d", &x);

                board[x][y].stack->p_color = players.player_color;

                players.own_pieces_captured--;

            }

        }

        else {


                printf("Enter the column of the stack you want to move:\n");
                scanf("%d", &position2);
                printf("Enter the row of the stack you want to move:\n");
                scanf("%d", &position1);


                if ((position1 < 0 || position1 > BOARD_SIZE) || (position2 < 0 || position2 >
                                                                                   BOARD_SIZE)) { //If the user inputs a space which is "out of bounds", this makes the user repeat their input
                    printf("Please pick a space which exists on the board\n");
                    legalMove = false;
                } else if (board[position1][position2].type ==
                           INVALID) {//If the user inputs a space which is not real, this makes the user repeat their input
                    printf("There is no valid space in that position, please choose another row and column: \n");
                    legalMove = false;
                } else if (board[position1][position2].stack == NULL) { //If the user inputs a space which has nothing in it, this makes the user repeat their input
                    printf("There is nothing in that square, please choose another row and column: \n");
                    legalMove = false;
                } else if (board[position1][position2].stack->p_color !=
                           players.player_color) {//If the user inputs a space which is not that user's color, this makes the user repeat their input
                    printf("Please pick a square which has your color: \n");
                    legalMove = false;
                } else
                    legalMove = true;


                legalMove = false;

                moveDist = getSize(board[position1][position2].stack);

                //loops the input for the player to enter a move if the given space is invalid
                while (!legalMove) {
                    printf("You have to move %d spaces\n",
                           moveDist); //Calculates the given distance that a piece can move

                    printf("Which column would you like to move to?\n"); //Sets up the variables for the new location of the stack
                    scanf("%d", &y);
                    printf("Which row would you like to move to?\n");
                    scanf("%d", &x);

                    while ((abs(x - position1) + abs(y - position2)) >
                           moveDist) { //If a location is within the allowed amount of moves, it passes through this while statement

                        printf("Please enter a column and row that are within the legal moving distance: \n");

                        printf("Which column would you like to move to?\n");
                        scanf("%d", &y);
                        printf("Which row would you like to move to?\n");
                        scanf("%d", &x);
                    }


                    if ((x < 0 || x > BOARD_SIZE) ||
                        (y < 0 || y > BOARD_SIZE)) { //Checks for inconsistencies with the new location for the stack
                        printf("Please pick a space which exists on the board\n");
                        legalMove = false;
                    } else if (board[x][y].type == INVALID) {
                        printf("There is no valid space in that position, please choose another row and column: \n");
                        legalMove = false;
                    } else
                        legalMove = true;

                }
                moveStack(position1, position2, x, y, players,
                          board); //After all original and new locations have me all the requirements, they are moved with moveStack

            }
    }
}

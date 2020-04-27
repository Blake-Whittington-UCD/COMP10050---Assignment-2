#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"



void moveStack(int position1, int position2, int a, int b, square board[BOARD_SIZE][BOARD_SIZE]){

    piece * top_of_current = board[position1][position2].stack; //Assigning the various boards with their respective titles

    piece * top_of_destination = board[a][b].stack;

    piece * current = top_of_current;


    if(board[position1][position2].stack->p_color == GREEN)
        board[a][b].stack->p_color = GREEN;
    else
        board[a][b].stack->p_color = RED;



    while(current->next != NULL){ //Takes the stack you want to move and finds the bottom of it

        current = current->next;

    }
    current->next = top_of_destination; //Takes the previously empty next piece of the current stack and "puts it on top" of the destination stack


    board[a][b].stack = top_of_current;
    //The new stack that has been created from both stacks is put on the grounds of the old stack


    board[position1][position2].stack = NULL;
    top_of_current = NULL; //The location of the old stack is now vacant so anything still there is dismissed



    board[a][b].num_pieces += board[position1][position2].num_pieces; //This combines the number of pieces from both stacks

    board[position1][position2].num_pieces = 0; //Resetting the old location's number of pieces after the stack has moved




}
int getSize(piece *top) {
    // Base case
    if (top == NULL)
        return 0;
    //returns 1 + the size of the stack
    return 1 + getSize(top->next);
}


void userMove(struct player players, square board[BOARD_SIZE][BOARD_SIZE]){

    int position1 = 0, position2 = 0, x = 0, y = 0, moveDist = 0;
    bool legalMove = false;
    printf("It's %s's player's turn\nPick a %s space\n", players.name, players.player_color==RED?"Green":"RED");
    //Gets the coordinates of the square to be moved
    while(!legalMove) {

        printf("Enter the position/coordinates from the stack you want to move: \n"); //Asks the user for input for the stack they want to move

        scanf("%d", &position2);
        scanf("%d", &position1);

        /**False when:
         * The top piece is not theirs
         * The space is invalid
         * The space is not on the board
         */
        if((position1 < 1 || position1 > BOARD_SIZE - 1) || (position2 < 1 || position2 > BOARD_SIZE - 1)){
            printf("Please pick a space which exists on the board\n");
            legalMove = false;
        }
        else if(board[position1][position2].type == INVALID){
            printf("There is no valid space in that position, please choose another row and column: \n");
            legalMove = false;
        }
        else if(board[position1][position2].stack->p_color != players.player_color){
            printf("Please pick a square which has your color: \n");
           legalMove = false;
        }

        else
            legalMove = true;
    }


    moveDist =  getSize(board[position1][position2].stack);
    legalMove = false;
    //loops the input for the player to enter a move if the given space is invalid
    while (!legalMove) {
        printf("You can move %d spaces\n", moveDist);

        printf("Which column would you move to?\n");
        scanf("%d", &y);
        printf("Which row would you move to?\n");
        scanf("%d", &x);


        /** False when:
         *  The square is too far to move to
         * The space is not valid
         *  The space is not on the board
         */
        //if (sqrt(pow(position1 - x, 2) + (pow(position2 - x, 2))) > moveDist || board[x][y].type == INVALID || (x < 1 || x > BOARD_SIZE - 1) || (y < 1 || y > BOARD_SIZE - 1)) {
           // printf("Can't move there. Pick another space");
            //legalMove = false;
       // }
       // else
            legalMove = true;
    }
    moveStack(position1,position2,x,y,board);


}

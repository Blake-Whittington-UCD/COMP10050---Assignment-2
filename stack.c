#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void pickStack(int position1, int position2){
    printf("Enter the position/coordinates from the stack you want to move: \n");
    scanf("%d", &position1);
    scanf("%d", &position2);
}

void moveStack(int position1, int position2, int a, int b, square board[BOARD_SIZE][BOARD_SIZE]){

    piece * top_of_current = board[position1][position2].stack; //Assigning the various boards with their respective titles

    piece * top_of_destination = board[a][b].stack;

    piece * current = top_of_current;

    while(current->next != NULL){ //Takes the stack you want to move and finds the bottom of it

        current = current->next;

    }
    current->next = board[a][b].stack; //Takes the previously empty next piece of the current stack and "puts it on top" of the destination stack


    board[a][b].stack = top_of_current;

    //The new stack that has been created from both stacks is put on the grounds of the old stack

    top_of_current = NULL; //The location of the old stack is now vacant so anything still there is dismissed

    board[a][b].num_pieces += board[position1][position2].num_pieces; //This combines the number of pieces from both stacks

    board[position1][position2].num_pieces = 0; //Resetting the old location's number of pieces after the stack has moved


}

void userMove(struct player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE]){
    int playerTurn = 0, allowedMove = 1, allowedStack = 1, winCon = 0;
    int position_x = 0, position_y = 0;

    while(playerTurn == 0){
        printf("Play rock, paper, scissors and input 1 if player 1 wins or input 2 if player 2 wins: \n");
        scanf("%d", &playerTurn);


        if(playerTurn == 1)
            printf("Player 1 will go first. \n");
        else if (playerTurn == 2)
            printf("Player 2 will go first. \n");
        else{
            playerTurn = 0;
        }
    }

    while(winCon != 1){

            while(allowedStack != 0){

                printf("It's Player 1's turn. \n");
                pickStack((int) &position_x, (int) &position_y);

                if(board[position_x][position_y].stack->p_color != players[playerTurn - 1].player_color){
                    allowedStack = 1;
                    printf("You picked another players stack, please pick again: \n");
                }
                else if(board[position_x][position_y].stack == NULL){
                    allowedStack = 1;
                    printf("Sorry, you picked a position on the board with no stack, please pick again: \n");
                }
                else
                    allowedStack = 0;
            }


            int moveLength = 0;


            char *moveString;

            while(allowedMove != 0){
                int temp = moveLength;
                moveLength = user_moving_instructions(temp,moveString);
            }


        }


    }

    

}

void transitionCalc(int *x, int *y, int moveLength, const char move_tracker[]){

    int i = 0;

    for(;i<moveLength;i++){

        if(move_tracker[i] =='L' || move_tracker[i]=='l') --*x;

        else if(move_tracker[i]=='R' || move_tracker[i]=='r') ++*x;

        else if(move_tracker[i]=='U' || move_tracker[i]=='u') --*y;

        else if (move_tracker[i]=='D' || move_tracker[i]=='d') ++*y;

    }
}

int user_moving_instructions(int moveLength, char move_tracker[]){
    int i = 0;


    printf("Enter what moves you are making: \n");
    printf("If you want to make a move, input r for right, l for left, u for up, and d for down.\n");

    scanf("%s", move_tracker);

    while(i<5){
        if(move_tracker[i] != '0')
            moveLength += 1;
        ++i;
    }

    return moveLength;
}

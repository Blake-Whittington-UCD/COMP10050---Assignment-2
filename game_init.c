
#include <stdio.h>
#include <stdlib.h>
#include "game_init.h"

void initialize_players() {

    printf("What is the name of Player 1?: \n"); //Stores the names of both players
    scanf("%s", player1.name);

    printf("What is the name of Player 2?: \n");
    scanf("%s", player2.name);

    player1.player_color = RED; //Sets each players colors
    player2.player_color = GREEN;

    player1.own_pieces_captured = 0;
    player2.own_pieces_captured = 0;

    player1.captured_pieces = 0;
    player2.captured_pieces = 0;
}

//Set Invalid Squares (where it is not possible to place stacks)
    set_invalid(square * s){

        s->type = INVALID;
        s->stack = NULL;
        s->num_pieces = 0;
    }


//Set Empty Squares (with no pieces/stacks)
    set_empty(square * s){

        s->type = VALID;
        s->stack = NULL;
        s->num_pieces = 0;
    }

//Set squares  with a GREEN piece
    set_green(square * s){

        s->type = VALID;
        s->stack = (piece *) malloc(sizeof(piece));
        s->stack->p_color = GREEN;
        s->stack->next = NULL;
        s->num_pieces = 1;
    }

//Set squares with a RED piece
    set_red(square * s){

        s->type = VALID;
        s->stack = (piece *) malloc(sizeof(piece));
        s->stack->p_color = RED;
        s->stack->next = NULL;
        s->num_pieces = 1;
    }


//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){

    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }
    }
}


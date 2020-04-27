
#include <stdio.h>
#include "player_switch.h"

void winCon(struct player players, square board[BOARD_SIZE][BOARD_SIZE]) {


    int playerWins = 0;

    int player_one_turn = 1, player_two_turn = 0;
    int redCounter = 0, greenCounter = 0, i = 0, j = 0;

    while (playerWins != 1) {


        print_board(board);


        for (i = 0; i < BOARD_SIZE; i++) {
            for ( j = 0; j < BOARD_SIZE; j++) {

                if (player_one_turn == 1) {

                    if (board[i][j].stack->p_color == GREEN) {

                    }
                        if (redCounter == 0 && i == 7 && j == 7) {

                            printf("Player 1 has won!!");
                            playerWins = 1;
                        }
                        else if (board[i][j].stack->p_color == RED)
                            redCounter++;
                    }
                    userMove(player1, board);
                }


                if (player_two_turn == 1) {

                    if (board[i][j].stack->p_color == RED) {

                        if (greenCounter == 0 && i == 7 && j == 7) {

                            printf("Player 2 has won!!");
                            playerWins = 1;
                        }
                    }
                    else if (board[i][j].stack->p_color == GREEN)
                        greenCounter++;
                }
                userMove(player2, board);
            }


            if (player_two_turn == 0) {
                player_two_turn++;
                player_one_turn--;
            }

            else if (player_one_turn == 0) {
                player_two_turn--;
                player_one_turn++;
            }


        greenCounter = 0;
        redCounter = 0;


    }

}





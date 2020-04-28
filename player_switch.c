
#include <stdio.h>
#include "player_switch.h"

void winCon(square board[BOARD_SIZE][BOARD_SIZE]) {

    int playerWins = 0;

    int player_one_turn = 1, player_two_turn = 0;
    int redCounter = 0, greenCounter = 0, i = 0, j = 0;

    while (playerWins != 1) { //If playerWins is equal to 1, that means that someone has won the game

        print_board(board); //Prints the board so that each player can make their choices on where to move

                if (player_one_turn == 1) { //If it's player one's turn the function enters this if statement

                    for (i = 0; i < BOARD_SIZE; i++) {
                        for (j = 0; j < BOARD_SIZE; j++) { //Checks to see if player 1 has won the game


                            if (board[i][j].stack!= NULL && board[i][j].stack->p_color == GREEN) {
                                if (redCounter == 0 && i == 7 && j == 7 && player1.own_pieces_captured == 0) {

                                    printf("%s(%u) has won with %d captured pieces!!\n", player1.name, player1.player_color, player1.captured_pieces );

                                    playerWins = 1;
                                }
                            }
                            else if (board[i][j].stack!= NULL && board[i][j].stack->p_color == RED)
                                    redCounter++;

                        }
                    }

                    userMove(player1, board); //If player 1 has not won yet, then the user is asked to move a stack
                }

        if (player_two_turn == 1) {

            for (i = 0; i < BOARD_SIZE; i++) {
                for (j = 0; j < BOARD_SIZE; j++) {//Checks to see if player 2 has won the game

                    if (board[i][j].stack!= NULL && board[i][j].stack->p_color == RED) {
                        if (greenCounter == 0 && i == 7 && j == 7 && player2.own_pieces_captured == 0) {

                            printf("%s(%u) has won with %d captured pieces!!\n", player2.name, player2.player_color, player2.captured_pieces );

                            playerWins = 1;
                        }
                    }
                    else if (board[i][j].stack!= NULL && board[i][j].stack->p_color == GREEN)
                        greenCounter++;

                }
            }

            userMove(player2, board); //If player 2 has not won yet, then the user is asked to move a stack
        }

            if (player_two_turn == 0) { //Once either player has made a move, these if statements are what allow the players to switch off taking turns
                player_two_turn++;
                player_one_turn--;
            }

            else if (player_one_turn == 0) {
                player_two_turn--;
                player_one_turn++;
            }

        greenCounter = 0; //The counters checking to see if there are any available pieces to move are reset
        redCounter = 0;

    }

}





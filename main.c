
#include <stdio.h>
#include "player_switch.h"


int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    printf("Player 1 goes first!\n");

    winCon(players[PLAYERS_NUM] , board);


    return 0;
}

#include <stdio.h>
#include "input_output.h"
#include "stack.h"


int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);


    print_board(board);

    userMove(&players[PLAYERS_NUM],  board);

    return 0;
}

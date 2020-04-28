
#include "player_switch.h"

int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players); //Initializes the players in data structures to be used for keeping track of each individual playing

    initialize_board(board); //Creates the board and sets all the board slots to be either non-usable, or a green/red board slot

    winCon(board); //This is the function which runs the game and checks to see if there is a winner

    return 0;
}

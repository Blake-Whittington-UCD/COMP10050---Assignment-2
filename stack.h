
#ifndef SOFTWAREENGINEERING_PROJECT2_STACK_H
#define SOFTWAREENGINEERING_PROJECT2_STACK_H

#endif //SOFTWAREENGINEERING_PROJECT2_STACK_H

#include "input_output.h"

void extraPieces(int a, int b, square board[BOARD_SIZE][BOARD_SIZE], struct player players );

void moveStack(int position1, int position2, int a, int b, struct player players, square board[BOARD_SIZE][BOARD_SIZE]);

void userMove(struct player players, square board[BOARD_SIZE][BOARD_SIZE]);



#ifndef SOFTWAREENGINEERING_PROJECT2_STACK_H
#define SOFTWAREENGINEERING_PROJECT2_STACK_H

#endif //SOFTWAREENGINEERING_PROJECT2_STACK_H

#include "game_init.h"


void pickStack(int position1, int position2);

void moveStack(int position1, int position2, int a, int b, square board[BOARD_SIZE][BOARD_SIZE]);

void userMove(struct player players[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE]);

void transitionCalc(int *x, int *y, int moveLength, const char move_tracker[]);

int user_moving_instructions(int moveLength, char move_tracker[]);
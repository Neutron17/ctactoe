#ifndef _NTR_INPUT_H_
#define _NTR_INPUT_H_ 1

#include "board.h"
// return value -> true = failure, false = success
bool handleInput(int inp, char *board, Player pl);
int getInput();
#endif


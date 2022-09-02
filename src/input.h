#ifndef _NTR_INPUT_H_
#define _NTR_INPUT_H_ 1

#include "board.h"
// return value -> true = failure, false = success
bool handleInput(int inp, char *restrict board, enum Player pl);
int getInput(void);

#endif


#include "input.h"

#include "utils.h"

int getInput(void) {
	write(STDOUT_NO, "Index: ", 7);
	char inp[2];
	read(STDIN_NO, inp, 2);
	char opt = inp[0] - '0';
	return opt;
}

bool handleInput(int inp, char *restrict board, enum Player pl) {
	if (inp < 1 || inp > 9)
		return true;
	if(isPlaceUsed(board, inp-1))
		return true;

	*(board + inp - 1) = 'O';
	return false;
}


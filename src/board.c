#include "utils.h"
#include "board.h"

void printBoard(const char *board) {
	for (char y = 0; y < 3; y++) {
		for (char x = 0; x < 3; x++) {
			write(STDOUT_NO, &board[x+y*3], 1);

			if (x != 2)
				write(STDOUT_NO, " | ", 3);
			else
				write(STDOUT_NO, "\n", 1);
		}
		if (y != 2)
			write(STDOUT_NO, "---------\n", 10);
	}
}

void compMove(char *board) {
	unsigned short x = randTo(8);
	while (x >= 8 || isPlaceUsed(board, x)) {
		x = randTo(8);
	}
	*(board + x) = 'X';
}
bool isPlaceUsed(const char *board, unsigned short index) {
	if (*(board + index) != ' ')
		return true;
	return false;
}
bool isBoardFull(const char *board) {
	for (short i = 0; i < 9; i++) {
		if (*(board + i) == ' ')
			return false;
	}
	return true;
}

char posLUT[8][3][2] = {
	{ {0,0}, {0,1}, {0,2} },
	{ {1,0}, {1,1}, {1,2} },
	{ {2,0}, {2,1}, {2,2} },

	{ {0,0}, {1,0}, {2,0} },
	{ {0,1}, {1,1}, {2,1} },
	{ {0,2}, {1,2}, {2,2} },

	{ {0,0}, {1,1}, {2,2} },
	{ {0,2}, {1,1}, {2,2} },
};

Player checkWinner(const char *board) {
	char icon = userIcon;
	Player ret = User;
	bool done = false;
top:;
	for(int pos = 0; pos < 8; pos++) {
		int succ = 0;
		for(int i = 0; i < 3; i++) {
			char h = posLUT[pos][i][0];
			char w = posLUT[pos][i][1];
			if(*(board + w + (h * 3)) == icon)
				succ++;
			else
				goto aft;

		}
		if(succ == 3)
			return ret;
aft:;
	}
	if(!done) {
		icon = compIcon;
		ret = Computer;
		done = true;
		goto top;
	}
	return None;
}


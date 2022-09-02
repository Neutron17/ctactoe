#include "utils.h"
#include "board.h"
#include "input.h"

void parseArgs(int argc, const char *argv[]);
void handler(int signal);

int main(int argc, const char *argv[]) {
	const enum Mode mode = PvC;

	srand(time(NULL));
	parseArgs(argc, argv);
	volatile bool running = true;
	char board[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	enum Player pl = User;
	if(mode == PvC) {
		enum Player winner;
		while(running) {
			if(isBoardFull(*board)) {
				printBoard(*board);
				write(STDOUT_NO, "DRAW\n", 5);
				if(checkWinner(*board) != None) {
					goto win;
				}
				return 0;
			}
			if (pl == User) {
				printBoard(*board);
				if (handleInput(getInput(), *board, pl)) {
					write(STDOUT_NO, "\n", 1);
					write(STDERR_NO, "Invalid input\n", 14);
					continue;
				}
			} else {
				compMove(*board);
			}
			if(pl) pl--;
			else pl++;
win:
			if((winner = checkWinner(*board)) != None) {
				printBoard(*board);
				if(winner == User) {
					write(STDOUT_NO, "You won\n", 8);
				}else{
					write(STDOUT_NO, "You lost\n", 9);
				}
				write(STDOUT_NO, "Game Over\n", 10);
				return 0;
			}
		}
	}else if(mode == PvP) {
		exit(2);
	}
	return 0;
}
void parseArgs(int argc, const char *argv[]) {
	if(argc != 1) {
	}
}


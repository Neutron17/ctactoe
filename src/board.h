#ifndef _NTR_BOARD_H_
#define _NTR_BOARD_H_ 1
#define userIcon 'O'
#define compIcon 'X'
#define bool unsigned char

enum Player {
	User,
	Computer,
	None
};

enum Mode {
	PvC,
	PvP
};

void printBoard(const char *restrict board);
void compMove(char *restrict board);
bool isPlaceUsed(const char *restrict board, unsigned short index);
bool isBoardFull(const char *restrict board);
enum Player checkWinner(const char *board);

#endif


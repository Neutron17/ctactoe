#ifndef _NTR_BOARD_H_
#define _NTR_BOARD_H_ 1
#define userIcon 'O'
#define compIcon 'X'
#define bool unsigned char

typedef enum {
	User,
	Computer,
	None
} Player;

typedef enum {
	PvC,
	PvP
} Mode;

void printBoard(const char *board);
void compMove(char* board);
bool isPlaceUsed(const char *board, unsigned short index);
bool isBoardFull(const char *board);
Player checkWinner(const char *board);
#endif


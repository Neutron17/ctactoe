#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>
#include "utils.h"
#include "color.h"

typedef enum Player {
	User,
	Computer
} Player;

void parseArgs(int argc, char *argv[]);
void printBoard(const char board[3][3]);
void handleInput(const int inp, char *board,Player pl);
int getInput();
void login();
void handler(int signal);

int main(int argc, char *argv[]) {
	errno = 0;
	signal(SIGINT, handler);
	parseArgs(argc, argv);
    volatile bool running = true;
    char board[3][3] = { 
        {' ', ' ', ' '},
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}
    };
    FILE *fptr = fopen("config.conf", "r+b");
    if(fptr == NULL) return EXIT_FAILURE;
    if(isFileEmpty(fptr)) {
        fptr = fopen("config.conf", "wb+");
        if(fptr == NULL) return EXIT_FAILURE;
        //login();
        fwrite(board, sizeof(board), 1, fptr);
    }else{
        fread(board, sizeof(board), 1, fptr);
        fclose(fptr);
    }

    Player pl = User;
    while(running) {
        printBoard(board);
        handleInput(getInput(), board, pl);
	if(pl) pl--;
	else pl++;
    }
    return 0;
}
void parseArgs(int argc, char *argv[]) {
    if(argc != 1) {
        fcprintf(stderr, Yellow, 
	"Warning: Unimplemented feature: Arguments\n");
    }
}
/*
x | x | x
----------
X | X | X
----------
X | X | X
*/
void printBoard(const char board[3][3]) {
    for(short x = 0; x<3; x++) {
        for(short y = 0; y<3; y++) {
            if(y != 2)
                printf("%c | ", board[x][y]);
            else
                printf("%c\n", board[x][y]);
        }
        if(x != 2) printf("---------\n");
    }
}
void login() {
    // TODO
    cprintf(Green, "Logging in...\n");
    printf("%s", ColToStr(Reset));
    FILE *f;
    if((f = fopen("users.bin", "rb")) == NULL) {
	    fcprintf(stderr, Red, "Couldn't open users.bin, login failed\nerrno: %d\nstrerr: %s\nAborting\n", errno, strerror(errno));
	    printf("%s", ColToStr(Reset));
	    raise(SIGKILL);
	    return;
    }
    if(isFileEmpty(f)) {
	    printf("No users detected\n");
	    printf("Creating new user...\n");
	    char *uname = readLine("Username: ");
	    if((f =fopen("users.conf","wb")) == NULL){
		    fcprintf(stderr, Red, "Couldn't open users.bin, login failed\nerrno: %d\nstrerr: %s\nAborting\n", errno, strerror(errno));
		    raise(SIGKILL);
		    return;
	    }
	    fwrite(uname, sizeof(uname), 1, f);
	    char temp[sizeof(uname)];
	    fread(temp, sizeof(uname), 1, f);
	    printf("Created user: %s\n", uname);
	    free(uname);
	    return;
    }

}
int getInput() {
	int opt = readInt("Index: ");
	if(opt == -1) handler(0);
	return opt;
}
void handleInput(const int inp,char *board,Player pl) {

	if(inp < 1 || inp > 9) {
		fcprintf(stderr,Red, 
			"Invalid option\n");
		return;
	}
	if(pl)
		*(board+inp-1) = 'X';
	else
		*(board+inp-1) = 'O';
	return;
}

void handler(int signal) {
	// TODO Are you sure question
	cprintf(Red, "Signal: %d\n", signal);
	raise(SIGKILL);
}


#include "utils.h"

static unsigned long seed;

void srand(unsigned s) {
	seed = s-1;
}

// source: ISO/IEC 9899
int rand() {
	seed = 1103515245 * seed + 12345;
	return seed >> 17;
}

int randTo(unsigned n) {
	return rand()%n;
}


#include "utils.h"

static unsigned long seed;

void srand(unsigned s) {
	seed = s-1;
}

// source: ISO/IEC 9899
//static const unsigned foo = (1103515245 + 12345) % (1 << 31);
int rand() {
	seed = 1103515245 * seed + 12345;
	return seed >> 17;
}

int randTo(unsigned n) {
	return rand()%n;
}


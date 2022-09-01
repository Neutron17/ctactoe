#include "utils.h"

static unsigned long seed;

void srand(unsigned s) {
	seed = s-1;
}

int rand() {
	seed = 6364136223846793005ULL*seed + 1;
	return seed>>33;
}

int randTo(unsigned n) {
	return rand()%n;
}


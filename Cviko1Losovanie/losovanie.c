#include "losovanie.h"
#include <stdlib.h> // funkcii rand()
#include <time.h> // funkcia time()

void vymen(MUINT index, MUINT i);

void losuj(MUINT pocetLosovanychZrebov) {
	srand((unsigned int)time(NULL)); // vždy rozdielny seed pre generátor nahodnych èísel

	for (MUINT i = 0; i < pocetLosovanychZrebov && i < pocetZrebov; i++) {
		MUINT index = rand() % (pocetZrebov - i) + i;
		vymen(index, i);
	}
}

void vymen(MUINT index, MUINT i) {
	struct Zreb temp;
	temp = zreby[index];
	zreby[index] = zreby[i];
	zreby[i] = temp;
}

#include "vystup.h"
#include <stdio.h>

void vypis(MUINT pocetLosovanychZrebov) {
	printf("\nVysledok zrebovania\n-------------------------\n");
	for (MUINT i = 0; i < pocetLosovanychZrebov; i++) {
		printf("%3u. poradie: \t%c %010u\n", i + 1, zreby[i].kod, zreby[i].cislo);
	}
}

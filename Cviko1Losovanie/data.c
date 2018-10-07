#include "data.h"
#include <malloc.h> // alokovanie pam‰ti

struct Zreb* zreby;
MUINT pocetZrebov;

void pripravZreby() {
	zreby = malloc(pocetZrebov * sizeof(struct Zreb)); // alokuje pam‰ù o veækosti ötrukt˙ri Zreb vynasobeny poËtom ûrebov
	for (MUINT i = 0; i < pocetZrebov; i++)	{
		zreby[i].cislo = i + 1;
		zreby[i].kod = 'A' + i % 26;
		//zreby[i].kod = (char)((i + 1) % 26);
	}
}

void zrusZreby() {
	if (zreby != NULL) {
		free(zreby); // p·rova funkcia k funcii malloc
	}
	zreby = NULL;
}

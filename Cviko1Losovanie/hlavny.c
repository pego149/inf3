#include "loteria.h"
#include <stdlib.h> // funkcia atoi()
#include <stdio.h>

/* TO DO
	o�etri� vstupy
*/


int main(int argc, char* argv[]) {
	if (sizeof(argv)==4 && atoi(argv[1])>0 && atoi(argv[2])>0)
	{
		int vstup1 = atoi(argv[1]);
		int vstup2 = atoi(argv[2]);
		if (vstup1 > vstup2)
		{
			vstup1 = atoi(argv[2]);
			vstup2 = atoi(argv[1]);
		}
		printf("Celkovy pocet zrebov: %u\nPocet losovanych zrebov: %u", vstup1, vstup2);
		pocetZrebov = vstup1;
		tah(vstup2);
		getchar();
		return 0;
	}
	else {
		printf("nazov_programu celkovy_po�et_�rebov po�et_losovan�ch_zrebov");
	}
}
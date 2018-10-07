#include "loteria.h"
#include <stdlib.h> // funkcia atoi()
#include <stdio.h>

/* TO DO
	ošetri vstupy
*/


int main(int argc, char* argv[]) {
	if (atoi(argv[1])!=0 && atoi(argv[2]) != 0)
	{
		int vstup1 = atoi(argv[1]);
		int vstup2 = atoi(argv[2]);
		if (vstup1 > vstup2)
		{
			vstup1 = atoi(argv[2]);
			vstup2 = atoi(argv[1]);
		}
		pocetZrebov = vstup1;
		tah(vstup2);
		getchar();
		return 0;
	}
	else {
		printf("nazov_programu celkovy_poèet_žrebov poèet_losovaných_zrebov");
	}
}
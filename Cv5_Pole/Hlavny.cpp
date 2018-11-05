#include "Pole.h"
#include <cstdio>

int main(int argc, char *argv[]) {
	if (argc == 2)
	{
		Pole pole(argv[1]);
		Pole polecopy(pole);
		pole.vypisNeparneCisla();
		polecopy.vypisNeparneCisla();
	}
	else
	{
		printf("Zadali ste zly vstup");
	}
}
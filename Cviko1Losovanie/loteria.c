#include "loteria.h"
#include "losovanie.h"
#include "vystup.h"

void tah(MUINT pocetLosovanychZrebov) {
	if (pocetLosovanychZrebov > pocetZrebov) {
		pocetLosovanychZrebov = pocetZrebov;
	}

	pripravZreby();
	losuj(pocetLosovanychZrebov);
	vypis(pocetLosovanychZrebov);
	zrusZreby();

}

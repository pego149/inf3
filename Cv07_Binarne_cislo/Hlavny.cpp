#include "BinCislo.h"
#include "VystupKonzola.h"
#include "VystupSubor.h"

int main() {
	BinCislo a("-1101"), b(30), c;
	c = "1111001";
	c = b + 4;
	c = 5 + a;
	VystupKonzola konzola;
	VystupSubor subor("cislo.txt");
	b.vypis(konzola);
	b.vypis(subor);
	return 0;
}
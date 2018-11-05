#include <cstdio>

class Pole
{
private:
	FILE *fhandle;
	int pocetCisel;
	int citajCislo();
	const char* menoSuboru;
	int* pole;
public:
	Pole(const char *meno);
	void vypisNeparneCisla();
	void kopirujPole(int* zdroj);
	Pole &operator = (const Pole &zdroj);
	Pole(const Pole &zdroj);
};
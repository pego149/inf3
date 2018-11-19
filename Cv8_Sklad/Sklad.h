#pragma once
#include "Tovar.h"
typedef int(*porovnajFunPtr)(const void *p1, const void *p2);

class Sklad
{
private:
	Tovar * aZasoby = nullptr;
	int aPocet = 0;
	Tovar *realokuj();
	void zobrazSort(porovnajFunPtr fun);
	void vypis(Tovar ** tovary);
public:
	Sklad();
	~Sklad() { delete[] aZasoby; };
	void pridaj(const char * nazov, double cena, int pocet);
	void vytvorPolePtr(Tovar **&zasoby);
	void zobrazPodlaNazov();
	void zobrazPodlaCena();
	void zobrazPodlaPocet();
};


#include "Sklad.h"
#include <iostream>


Sklad::Sklad()
{
}

int porovnajNazov(const void *op1, const void *op2) 
{
	Tovar **ptrt1 = (Tovar **)op1;
	Tovar **ptrt2 = (Tovar **)op2;
	return *(*ptrt1) < *(*ptrt2);
}

int porovnajCena(const void *op1, const void *op2)
{
	Tovar **ptrt1 = (Tovar **)op1;
	Tovar **ptrt2 = (Tovar **)op2;
	int ret = (*ptrt1)->getCena() - (*ptrt2)->getCena();
	if (ret == 0)
	{
		ret = strcmp((*ptrt1)->getNazov(), (*ptrt2)->getNazov());
		if (ret == 0)
		{
			ret = (*ptrt1)->getPocet() - (*ptrt2)->getPocet();
		}
	}
	return ret;
}

int porovnajPocet(const void *op1, const void *op2)
{
	return 0;
}

Tovar * Sklad::realokuj()
{
	Tovar *pom = new Tovar[aPocet + 1];
	if (aZasoby)
	{
		for (int i = 0; i < aPocet; i++)
		{
			pom[i] = aZasoby[i];
		}
		delete[] aZasoby;
	}
	aPocet++;
	return pom;
}

void Sklad::zobrazSort(porovnajFunPtr fun)
{
	Tovar **ptrzasob;
	vytvorPolePtr(ptrzasob);
	qsort(ptrzasob, aPocet, sizeof(Tovar*), fun);
	vypis(ptrzasob);
	delete[] ptrzasob;
}

void Sklad::vypis(Tovar ** tovary)
{
	for (int i = 0; i < aPocet; i++)
	{
		std::cout << *tovary[i] << std::endl;
	}
}

void Sklad::pridaj(const char * nazov, double cena, int pocet)
{
	if (nazov && *nazov) 
	{
		aZasoby = realokuj();
		aZasoby[aPocet - 1].setNazov(nazov);
		aZasoby[aPocet - 1].setCena(cena);
		aZasoby[aPocet - 1].setPocet(pocet);
	}
	
}

void Sklad::vytvorPolePtr(Tovar **& zasoby)
{
	zasoby = new Tovar *[aPocet];
	for (int i = 0; i < aPocet; i++)
	{
		zasoby[i] = &aZasoby[i]; 
	}
}

void Sklad::zobrazPodlaNazov()
{
	std::cout << "Podla nazvu: " << std::endl << "------------------" << std::endl;
	Tovar::styp = 0;
	zobrazSort(porovnajNazov);
}

void Sklad::zobrazPodlaCena()
{
	std::cout << "Podla ceny: " << std::endl << "------------------" << std::endl;
	Tovar::styp = 1;
	zobrazSort(porovnajCena);
}

void Sklad::zobrazPodlaPocet()
{
	std::cout << "Podla poctu: " << std::endl << "------------------" << std::endl;
	Tovar::styp = 2;
	zobrazSort(porovnajPocet);
}

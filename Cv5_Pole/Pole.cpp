#include <cstdio>
#include "Pole.h"




int Pole::citajCislo()
{
	if (fhandle != nullptr)
	{
		if (!feof(fhandle))
		{
			int cislo;
			fscanf(fhandle, "%d", &cislo); //&cislo!!!
			return cislo;
		}
	}
	return 0;
}

Pole::Pole(const char * meno)
{	
	if (meno) {
		menoSuboru = meno;
		fhandle = fopen(meno, "rt");
		pocetCisel = citajCislo();
		pole = new int[pocetCisel];
		for (int i = 0; i < pocetCisel; i++)
		{
			pole[i] = citajCislo();
		}
		fclose(fhandle);
	}

}

void Pole::vypisNeparneCisla()
{
	for (int i = 0; i < pocetCisel; i++)
	{
		if (pole[i] % 2 == 1)
		{
			printf("%d\n",pole[i]);
		}
	}
}

void Pole::kopirujPole(int* zdroj)
{	
	//int* nPole = new int[pocetCisel];
	for (int i = 0; i < pocetCisel; i++)
	{
		pole[i] = zdroj[i];
	}
}

Pole & Pole::operator=(const Pole & zdroj)
{
	if (this != &zdroj)
	{
		delete[] pole;
		pocetCisel = zdroj.pocetCisel;
		kopirujPole(zdroj.pole);
	}
	return *this;
}

Pole::Pole(const Pole & zdroj)
{
	pocetCisel = zdroj.pocetCisel;
	kopirujPole(zdroj.pole);
}

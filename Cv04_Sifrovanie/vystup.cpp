#include "vystup.h"
#include <cstring>
#include <cstdio>
#include <iostream>
#include "funkcie.h"

using namespace std;

Vystup::Vystup(const char *menoSuboru)
{
	aMenoSuboru = kopirujRetazec(menoSuboru);
}

Vystup::Vystup(const Vystup &zdroj)
{
	aMenoSuboru = kopirujRetazec(zdroj.aMenoSuboru);
}

Vystup & Vystup::operator=(const Vystup & zdroj)
{
	if (this != &zdroj)
	{
		delete[] aMenoSuboru;
		aMenoSuboru = kopirujRetazec(zdroj.aMenoSuboru);
	}
	return *this;
}

Vystup::~Vystup()
{
}

void Vystup::zapis(unsigned char * text)
{
	if (text && *text)
	{
		if (aMenoSuboru && *aMenoSuboru)
		{
			int dlzka = strlen((char *)text);
			FILE *f = fopen(aMenoSuboru, "wb");
			if (f)
			{
				fwrite(text, dlzka, 1, f);
				fclose(f);
			}
		}
		else
		{
			cout << text << endl;
		}
	}
}

#include "vstup.h"
#include "funkcie.h"
#include <cstdio>
#include <cstring>


unsigned Vstup::dajDlzkuSuboru()
{
	unsigned dlzka(0);
	if (aMenoSuboru)
	{
		FILE *f = fopen(aMenoSuboru, "rb");
		if (f)
		{
			fseek(f, 0, SEEK_END);
			dlzka = ftell(f);
			fclose(f);
		}
	}
	return dlzka;
}

Vstup::Vstup(const char *menoSuboru)
{
	aMenoSuboru = kopirujRetazec(menoSuboru);/*
	if (menoSuboru && *menoSuboru)
	{
		int dlzka = strlen(menoSuboru);
		aMenoSuboru = new char[dlzka + 1];
		strcpy(aMenoSuboru, menoSuboru);
	}*/
}

Vstup::Vstup(const Vstup & zdroj)
{
	aMenoSuboru = kopirujRetazec(zdroj.aMenoSuboru);
}


Vstup & Vstup::operator=(const Vstup & zdroj)
{
	if (this != &zdroj)
	{
		delete[] aMenoSuboru;
		aMenoSuboru = kopirujRetazec(zdroj.aMenoSuboru);
	}
	return *this;
}

Vstup::~Vstup()
{
}

unsigned char * Vstup::citaj()
{
	if (aMenoSuboru)
	{
		int dlzka = dajDlzkuSuboru();
		if (dlzka > 0)
		{
			unsigned char *text = new unsigned char[dlzka + 1];
			if (text)
			{
				FILE *f = fopen(aMenoSuboru, "rb");
				if (f)
				{
					fread(text, dlzka, 1, f);
					text[dlzka] = '\0'; //dolezite
					fclose(f);
					return text;
				}
			}
		}
	}
	return nullptr;
}

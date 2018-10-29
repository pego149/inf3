#include "sifrator.h"
#include "funkcie.h"
#include "vstup.h"
#include "vystup.h"
#include "koder.h"
#include <cctype>


void Sifrator::init(char cinnost, const char * heslo, const char * vstupSubor, bool konzola, const char * vystupSubor)
{
	aCinnost = tolower(cinnost);
	aCinnost = (aCinnost != 's' && aCinnost != 'd' && aCinnost != 'h') ? 'h' : aCinnost;
	aHeslo = kopirujRetazec(heslo);
	if (!(aHeslo && *aHeslo))
	{
		aCinnost = 'h';
	}
	aVstupnySubor = kopirujRetazec(vstupSubor);
	if (!(vstupSubor && *vstupSubor))
	{
		aCinnost = 'h';
	}
	aKonzola = konzola;
	aVystupnySubor = kopirujRetazec(vystupSubor);
	if (!(vystupSubor && *vystupSubor))
	{
		aKonzola = true;
	}
}

void Sifrator::zmaz()
{
	delete[]aVystupnySubor;
	delete[]aVstupnySubor;
	delete[]aHeslo;
}

void Sifrator::vypisHelp()
{
	Vystup konzola(nullptr);
	konzola.zapis((unsigned char *)"sifrator CINNOST VST_SUBOR [TYP_VYSTUPU VYST_SUBOR]\n"
		"\tCINNOST:\n"
		"\t\ts...sifrovanir\n"
		"\t\td...desifrovanie\n"
		"\t\th...help\n"
		"\tTYP_VYSTUPU:\n"
		"\t\ts...subor\n"
		"\t\tc...konzola");
}

Sifrator::Sifrator(char cinnost, const char * heslo, const char * vstupSubor, bool konzola, const char * vystupSubor)
{
	init(cinnost, heslo, vstupSubor, konzola, vystupSubor);
}

Sifrator::Sifrator(const Sifrator & zdroj)
{
	init(zdroj.aCinnost, zdroj.aHeslo, zdroj.aVstupnySubor, zdroj.aKonzola, zdroj.aVystupnySubor);
}

Sifrator & Sifrator::operator=(const Sifrator & zdroj)
{
	if (this != &zdroj) 
	{
		zmaz();
		init(zdroj.aCinnost, zdroj.aHeslo, zdroj.aVstupnySubor, zdroj.aKonzola, zdroj.aVystupnySubor);
	}
	return *this;
}

Sifrator::~Sifrator()
{
	zmaz();
}

void Sifrator::Start()
{
	if (aCinnost == 'h')
	{
		vypisHelp();
	}
	else
	{
		unsigned char *zdrojText = Vstup(aVstupnySubor).citaj();
		if (zdrojText)
		{
			unsigned char *cielText = (aCinnost == 's') ? Koder().koduj((unsigned char *)aHeslo, zdrojText) : Koder().dekoduj((unsigned char *)aHeslo, zdrojText);
			if (cielText)
			{
				Vystup(aVystupnySubor).zapis(cielText);
				delete[]cielText;
			}
			delete[]zdrojText;
		}
		else
			vypisHelp();
	}
}

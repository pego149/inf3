#include "Koder.h"
#include <random>
#include "Heslo.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>



void Koder::zakodujTabulku(const unsigned char * heslo)
{
	unsigned int nasada = DajNasadu(heslo);
	std::default_random_engine generator;
	generator.seed(nasada);
	for (int i = 0; i < DLZKA_TABULKY; i++)
	{
		std::uniform_int_distribution<int> distribution(0, DLZKA_TABULKY - i);
		int index = distribution(generator);
		vymen(aKodTabulka[index], aKodTabulka[DLZKA_TABULKY - 1 - i]);
	}
}

void Koder::dekodujTabulku()
{
	unsigned char pomocnaTabulka[DLZKA_TABULKY];
	for (int i = 0; i < DLZKA_TABULKY; i++)
	{
		pomocnaTabulka[aKodTabulka[i]] = pomocnaTabulka[i];
	}
	memmove(aKodTabulka, pomocnaTabulka, DLZKA_TABULKY * sizeof(unsigned char));
}

unsigned Koder::DajNasadu(const unsigned char * heslo)
{
	//Heslo h(heslo);
	//return h.DajNasadu();
	return Heslo(heslo).dajNasadu();
}

void Koder::vymen(unsigned char & a, unsigned char & b)
{
	unsigned char c(a);
	a = b;
	b = c;
}

void Koder::vymen(unsigned char * a, unsigned char * b)
{
	if (a && b) {
		char temp = *a;
		*a = *b;
		*b = temp;
	}
}

Koder::Koder()
{
	for (int i = 0; i < DLZKA_TABULKY; i++)
	{
		aKodTabulka[i] = i;
	}
}


Koder::~Koder()
{
}

unsigned char * Koder::koduj(const unsigned char * heslo, const unsigned char * text)
{
	unsigned char *rettext = nullptr;
	if (heslo && text && *text)
	{
		zakodujTabulku(heslo);
		int dlzka = strlen((char *)text);
		unsigned char *zakodovanyText = new unsigned char[dlzka]; //nie je retazec
		if (zakodovanyText)
		{
			for (int i = 0; i < dlzka; i++)
			{
				zakodovanyText[i] = aKodTabulka[text[i]];
			}
			unsigned char *zasifrovanyText = new unsigned char[3 * dlzka + 1]; //bude to retazec
			if (zasifrovanyText)
			{
				unsigned char *ps = zasifrovanyText;
				for (int i = 0; i < dlzka; i++)
				{
					char buf[4];
					sprintf_s(buf, "%03u", zakodovanyText[i]);
					memmove(ps, buf, 3);
					ps += 3;
				}
				*ps = '\0';
				rettext = zasifrovanyText;
			}
			delete[]zakodovanyText;
		}
	}
	return rettext;
}

unsigned char * Koder::dekoduj(const unsigned char * heslo, const unsigned char * sifrtext)
{
	if (heslo != nullptr && sifrtext != nullptr && *sifrtext != 0) // heslo && sifrtext && *sifrtext
	{
		zakodujTabulku(heslo);
		dekodujTabulku();
		int dlzka = strlen((char *)sifrtext);
		unsigned char *desifrovanyText = new unsigned char[dlzka / 3 + 1];
		if (desifrovanyText)
		{
			int k = 0;
			char buf[4]{};
			for (int i = 0; i < dlzka; i++)
			{
				memmove(buf, &sifrtext[i], 3);
				desifrovanyText[k++] = aKodTabulka[atoi(buf)];
			}
			desifrovanyText[k] = '\0';
			return desifrovanyText;
		}
	}
	return nullptr;
}

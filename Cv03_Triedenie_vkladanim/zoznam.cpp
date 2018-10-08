#include "zoznam.h"
#include "vstup.h"
#include "vystup.h"



void Zoznam::sort(const char * menoSuboru, porovnajPtr compareFun)
{
	if (menoSuboru != nullptr && *menoSuboru != 0)
	{
		Vstup citac(menoSuboru);
		Uzol *predchadzajuci, *uzol;
		int cislo = citac.citajCislo();
		while (cislo != neplatna_hodnota)
		{
			if (start == nullptr)
			{
				start = new Uzol(cislo, nullptr);
			}
			else
			{
				predchadzajuci = nullptr;
				uzol = start;
				while (uzol != nullptr && compareFun(&cislo, &uzol->hodnota) > 0)
				{
					predchadzajuci = uzol;
					uzol = uzol->dalsi;
				}
				uzol = new Uzol(cislo, uzol);
				if (predchadzajuci == nullptr)
				{
					start = uzol;
				}
				else
				{
					predchadzajuci->dalsi = uzol;
				}
			}
			cislo = citac.citajCislo();
		}
	}
}

void Zoznam::uloz(const char * menoSuboru)
{
	Uzol *uzol = start;
	Vystup vystup(menoSuboru);
	while (uzol!=nullptr)
	{
		vystup.zapisCislo(uzol->hodnota);
		uzol = uzol->dalsi;
	}
}

Zoznam::~Zoznam()
{
	vymaz(start);
}

void Zoznam::vymaz(Uzol * uzol)
{
	if (uzol->dalsi != nullptr) 
	{
		vymaz(uzol->dalsi);
	}
	delete uzol;
}

#include "Tovar.h"

int Tovar::styp = 0;

bool operator<(Tovar & op1, Tovar & op2)
{
	switch (Tovar::styp)
	{
	case 0:
		return strcmp(op1.aNazov, op2.aNazov);
	case 1:
		return op1.aCena < op2.aCena;
	case 2:
		return op1.aPocet < op2.aPocet;
	default:
		return false;
	}
}

std::ostream & operator<<(std::ostream & os, Tovar & t)
{
	switch (Tovar::styp)
	{
	case 0:
		os << "Nazov: " << t.aNazov << std::endl;
		os << "Cena: " << t.aCena << std::endl;
		os << "Pocet: " << t.aPocet << std::endl;
		break;
	case 1:
		os << "Cena: " << t.aCena << std::endl;
		os << "Nazov: " << t.aNazov << std::endl;
		os << "Pocet: " << t.aPocet << std::endl;
		break;
	case 2:
		os << "Pocet: " << t.aPocet << std::endl;
		os << "Nazov: " << t.aNazov << std::endl;
		os << "Cena: " << t.aCena << std::endl;
		break;
	default:
		return os;
	}
}

char * kopirujRetazec(const char * zdrojRetazec)
{
	char *ciel(nullptr); //*ciel = nullptr;
	if (zdrojRetazec && *zdrojRetazec)
	{
		int dlzka = strlen(zdrojRetazec);
		ciel = new char[dlzka + 1];
		strcpy(ciel, zdrojRetazec);
	}
	return nullptr;
}
#include "funkcie.h"
#include <cstring>

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

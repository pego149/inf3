#include "vstup.h"

Vstup::Vstup(const char * menoSuboru)
{
	fhandle = nullptr;
	if (*menoSuboru != NULL && *menoSuboru != 0) // *menoSuboru != '\0'
	{
		fhandle = fopen(menoSuboru, "rt");
	}
}

Vstup::~Vstup()
{
	if (fhandle != nullptr)
	{
		fclose(fhandle);
	}
}

int Vstup::citajCislo()
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
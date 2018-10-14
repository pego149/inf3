#include "vystup.h"



Vystup::Vystup(const char *menoSuboru)
{	
	if (menoSuboru && *menoSuboru )
	{
		fhandle = fopen(menoSuboru, "wt");
	}
}


Vystup::~Vystup()
{
	if (fhandle != nullptr)
	{
		fclose(fhandle);
	}
}

void Vystup::zapisCislo(int cislo)
{
	if (fhandle != nullptr)
	{
		if (cislo % 2 == 0)
		{
			fprintf(fhandle, "%d\n", cislo);
			printf("%d\n", cislo);
		}
	}
}

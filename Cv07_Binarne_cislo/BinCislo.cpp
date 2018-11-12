#include "BinCislo.h"
#include <cstring>
#include <cmath>

llong BinCislo::bin2Dec(const char * pstrcislo)
{
	llong deccislo = 0;
	if (pstrcislo && *pstrcislo) {
		char *pomcislo = new char[strlen(pstrcislo) + 1];
		strcpy(pomcislo, pstrcislo);
		strrev(pomcislo);
		int i = 0;
		llong jednotka = 1;
		while (pomcislo[i])
		{
			if (pomcislo[i] == '1')
			{
				deccislo += (jednotka << i); //bitovy posun je rychlejsi ako pow
			}
			i++;
		}
		/*for (int j = 0; j < strlen(pomcislo); j++)
		{
			deccislo += powl(2, pomcislo[j]);
		}*/
		if (pstrcislo[0] == '-')
		{
			deccislo = -deccislo;
		}
		delete[] pomcislo;
	}
	return deccislo;
}

const char * BinCislo::dec2Bin(char * bincislo, llong pdekcislo)
{
	llong pomcislo(abs(pdekcislo));
	int i = 0; //int i(0);
	if (bincislo) 
	{
		do
		{
			bincislo[i++] = pomcislo % 2 + 0x30; //prevod cisla 0 alebo 1 na znak '0', '1'
			pomcislo >>= 1; //pomcislo /= 2;
		} while (pomcislo > 0);
		if (pdekcislo < 0)
		{
			bincislo[i++] = '-';
		}
		bincislo[i] = '\0';
	}
	return strrev(bincislo);
}

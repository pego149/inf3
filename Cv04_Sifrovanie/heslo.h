#pragma once
#include <cstring>
const unsigned DLZKA_HESLA = 8;
class Heslo
{
private:
	union
	{
		unsigned char aHeslo[DLZKA_HESLA];
		long long aNasada{ 0 };
	};
public:
	Heslo(const unsigned char *heslo)
	{
		if (heslo && *heslo)
		{
			int dlzka = strlen((char *)heslo);
			dlzka = dlzka > DLZKA_HESLA ? DLZKA_HESLA : dlzka;
			memmove(aHeslo, heslo, dlzka); //priamy pristup v pamati
		}
	}
	unsigned int dajNasadu()
	{
		unsigned int nasada1 = aNasada & 0x00000000ffffffff;
		unsigned int nasada2 = (aNasada >> 32) & 0x00000000ffffffff;
		return nasada1 + nasada2;
	}
};


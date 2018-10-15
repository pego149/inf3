#include "vystup.h"
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

Vystup::Vystup(const char *menoSuboru)
{
}

Vystup::Vystup(const Vystup &zdroj)
{
}

Vystup & Vystup::operator=(const Vystup & zdroj)
{
	// TODO: insert return statement here
	return *this;
}

Vystup::~Vystup()
{
}

void Vystup::zapis(unsigned char * text)
{
	if (text && *text)
	{
		int dlzka = strlen((char *)text);
		FILE *f = fopen(aMenoSuboru, "wb");
		if (f)
		{
			fwrite(text, dlzka, 1, f);
			fclose(f);
		}
		else
		{
			cout << text << endl;
		}
	}
}

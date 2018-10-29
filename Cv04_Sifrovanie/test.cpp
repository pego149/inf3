#include "test.h"
#include "koder.h"
#include "vystup.h"
#include <cstring>

Test::Test()
{
}

bool Test::testuj()
{
	Koder koder;
	unsigned char *zasifrovanyText = koder.koduj((unsigned char*)"abc123", (unsigned char*)"pondelok rano");
	unsigned char *povodnyText = Koder().dekoduj((unsigned char*)"abc123", zasifrovanyText);

	Vystup v("");
	v.zapis(zasifrovanyText);
	v.zapis(povodnyText);
	int ret = strcmp("pondelok rano", (char *)povodnyText);
	delete[] povodnyText;
	delete[] zasifrovanyText;
	return ret == 0 ? true : false;
}


Test::~Test()
{
}

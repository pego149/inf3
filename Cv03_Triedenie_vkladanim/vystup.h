#pragma once
#include <cstdio>

struct Vystup
{
	FILE *fhandle = nullptr;
	Vystup(const char *menoSuboru);
	~Vystup();
	void zapisCislo(int cislo);
};


#pragma once
//#include <stdio.h> //kniznica z jazyka c.
#include <cstdio>

struct Vstup
{
	FILE *fhandle;
	Vstup(const char *menoSuboru);
	~Vstup();

	int citajCislo();

};
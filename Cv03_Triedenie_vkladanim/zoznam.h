#pragma once
#include "uzol.h"

typedef int(*porovnajPtr)(void * uzol1, void * uzol2);

struct Zoznam
{
	Uzol *start = nullptr;
	void sort(const char *menoSuboru, porovnajPtr compareFun);
	void uloz(const char *menoSuboru);
	~Zoznam();
	void vymaz(Uzol *uzol);
};


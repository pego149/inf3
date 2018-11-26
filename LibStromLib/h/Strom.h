#pragma once
#include "Uzol.h"
class Strom
{
	Uzol *koren;
	void zrusStrom(Uzol *list);
	void vloz(int data, Uzol *list);
	Uzol *najdi(int data, Uzol *list);
	void vypis(Uzol *list);
public:
	Strom() : koren(nullptr) {}
	~Strom() { zrusStrom(); }
	void zrusStrom();
	void vloz(int data);
	Uzol *najdi(int data);
	void vypis();
};


#pragma once
typedef int TYPHODNOTA;
const TYPHODNOTA neplatna_hodnota = 0;

int porovnaj(void *cislo1ptr, void *cislo2ptr);
struct Uzol
{
	Uzol(TYPHODNOTA phodnota, Uzol *pdalsi);
	TYPHODNOTA hodnota;
	Uzol *dalsi = nullptr;
};


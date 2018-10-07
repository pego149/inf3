#pragma once
//#ifndef DATA_H
//#define DATA_H

//#ifdef WIN32
//#define MUINT unsigned int// MÙjUnignetInt v pripade windowsu
//#else
//#define MUINT unsigned long // v pripade linuxu MUINT o veækosti 4 bajtov
//#endif // WIN32

enum {FALSE, TRUE};
typedef unsigned int MUINT;
typedef unsigned short BOOL; // lebo jazyk C nepozn· boolean

// vyalokuje poûadovanÈ miesto na halde 
// a inicializuje jednotlive ûreby
void pripravZreby();
// dealokuje miesto v dynamickej pam‰ti
void zrusZreby();

struct Zreb {
	MUINT cislo;
	char kod;
};

extern MUINT pocetZrebov; // zabezpeËime ûe t·to premenn· sa tu nevytvorÌ (iba ju tu deklarujeme), ale mÙûe byù definovana(inicializovan·) niekde inde
extern struct Zreb* zreby; // smernik na pole Zreb-ov

//#endif // !DATA_H
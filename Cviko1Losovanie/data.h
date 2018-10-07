#pragma once
//#ifndef DATA_H
//#define DATA_H

//#ifdef WIN32
//#define MUINT unsigned int// M�jUnignetInt v pripade windowsu
//#else
//#define MUINT unsigned long // v pripade linuxu MUINT o ve�kosti 4 bajtov
//#endif // WIN32

enum {FALSE, TRUE};
typedef unsigned int MUINT;
typedef unsigned short BOOL; // lebo jazyk C nepozn� boolean

// vyalokuje po�adovan� miesto na halde 
// a inicializuje jednotlive �reby
void pripravZreby();
// dealokuje miesto v dynamickej pam�ti
void zrusZreby();

struct Zreb {
	MUINT cislo;
	char kod;
};

extern MUINT pocetZrebov; // zabezpe�ime �e t�to premenn� sa tu nevytvor� (iba ju tu deklarujeme), ale m��e by� definovana(inicializovan�) niekde inde
extern struct Zreb* zreby; // smernik na pole Zreb-ov

//#endif // !DATA_H
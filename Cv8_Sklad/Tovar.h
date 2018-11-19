#pragma once
#include <ostream>
#include <cstring>
char *kopirujRetazec(const char* zdroj);

class Tovar
{
private:
	char * aNazov = nullptr;
	double aCena = 0;
	int aPocet = 0;
public:
	static int styp;
	Tovar() {}
	~Tovar() { delete[] aNazov; }
	Tovar(const Tovar & zdroj) : aNazov(kopirujRetazec(zdroj.aNazov)), aCena(zdroj.aCena), aPocet(zdroj.aPocet) {}
	Tovar &operator = (const Tovar & zdroj)
	{
		if (this != &zdroj)
		{
			delete[] aNazov;
			aNazov = kopirujRetazec(zdroj.aNazov);
			aCena = zdroj.aCena;
			aPocet = zdroj.aPocet;
		}
		return *this;
	}
	char *getNazov() { return aNazov; }
	double getCena() { return aCena; }
	int getPocet() { return aPocet; }
	void setNazov(const char * pNazov) { aNazov = kopirujRetazec(pNazov); }
	void setCena(double pCena) { aCena = pCena; }
	void setPocet(int pPocet) { aPocet = pPocet; }

	friend bool operator <(Tovar & op1, Tovar & op2);
	friend std::ostream &operator << (std::ostream &os, Tovar &t);
};


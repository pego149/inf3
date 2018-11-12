#pragma once
#include "IVystup.h"

typedef long long llong;

class BinCislo
{
private:
	llong aHodnota = 0;
	llong bin2Dec(const char *pstrcislo);
	const char *dec2Bin(char *bincislo, llong pdekcislo);
public:
	BinCislo(const char *pstrcislo) :aHodnota(bin2Dec(pstrcislo)) {};
	BinCislo(llong pdekcislo = 0) :aHodnota(pdekcislo) {};
	void vypis(IVystup &pvystup) {
		char pombuf[66];
		pvystup.Vypis(dec2Bin(pombuf, aHodnota));
	};
	friend BinCislo operator + (BinCislo op1, BinCislo op2);
	friend BinCislo operator - (BinCislo op1, BinCislo op2);
	friend BinCislo operator * (BinCislo op1, BinCislo op2);
	friend BinCislo operator / (BinCislo op1, BinCislo op2);
	friend bool operator < (BinCislo op1, BinCislo op2);
	friend bool operator > (BinCislo op1, BinCislo op2);
	friend bool operator >= (BinCislo op1, BinCislo op2);
	friend bool operator <= (BinCislo op1, BinCislo op2);
};

inline BinCislo operator + (BinCislo op1, BinCislo op2) {
	return op1.aHodnota + op2.aHodnota;
}

inline BinCislo operator - (BinCislo op1, BinCislo op2) {
	return op1.aHodnota - op2.aHodnota;
}

inline BinCislo operator * (BinCislo op1, BinCislo op2) {
	return op1.aHodnota * op2.aHodnota;
}

inline BinCislo operator / (BinCislo op1, BinCislo op2) {
	return op1.aHodnota / op2.aHodnota;
}

inline bool operator < (BinCislo op1, BinCislo op2) {
	return op1.aHodnota < op2.aHodnota;
}

inline bool operator > (BinCislo op1, BinCislo op2) {
	return op1.aHodnota > op2.aHodnota;
}

inline bool operator >= (BinCislo op1, BinCislo op2) {
	//return op1.aHodnota >= op2.aHodnota;
	return !(op1 < op2);
}

inline bool operator <= (BinCislo op1, BinCislo op2) {
	//return op1.aHodnota >= op2.aHodnota;
	return !(op1 > op2);
}


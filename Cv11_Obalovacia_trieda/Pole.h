#pragma once
#include <iostream>
#include "VynimkaIndex.h"

using namespace std;

template <class T>
class Pole
{
	unsigned int aRozsah;
	int aDolnyIndex;
	T *aData;
	void copy(const Pole *zdroj);
	void zmaz();
public:
	Pole(int pDolnyIndex, unsigned int pRozsah, T initval);
	Pole(const Pole &zdroj) { copy(zdroj); }
	Pole &operator =(const Pole &zdroj) 
	{
		if (&zdroj)
		{
			zmaz();
			copy(zdroj);
		}
		return *this;
	}
	T &operator [](int index);
	void vypis();
	~Pole();
};


template<class T>
inline void Pole<T>::copy(const Pole * zdroj)
{
	aRozsah = zdroj->aRozsah;
	aDolnyIndex = zdroj->aDolnyIndex;
	aData = nullptr;
	if (aRozsah != 0)
	{
		aData = new T[aRozsah];
		for (int i = 0; i < aRozsah; i++)
		{
			aData[i] = zdroj->aData[i];
		}
	}
}

template<class T>
inline void Pole<T>::zmaz()
{
	if (aData)
	{
		delete[] aData;
	}
	aData = nullptr;
	aRozsah = 0;
}

template <class T>
Pole<T>::Pole(int pDolnyIndex, unsigned int pRozsah, T initval)
	:aRozsah(pRozsah), aDolnyIndex(pDolnyIndex), aData(aRozsah != 0 ? new T[aRozsah] : nullptr)
{
	for (int i = 0; i < aRozsah; i++)
	{
		aData[i] = initval;
	}
}

template<class T>
inline T & Pole<T>::operator[](int index)
{
	if (index<aDolnyIndex)
	{
		throw VynimkaDolnyIndex(aDolnyIndex);
	}
	int hornyRozsah = aDolnyIndex + aRozsah - 1;
	if (index > hornyRozsah)
	{
		throw VynimkaHornyIndex(hornyRozsah);
	}
	return aData[index - aDolnyIndex];
}

template<class T>
inline void Pole<T>::vypis()
{
	for (int i = 0; i < aRozsah; i++)
	{
		cout << aData[i] << endl;
	}
	cout << endl;
}

template <class T>
Pole<T>::~Pole()
{
}

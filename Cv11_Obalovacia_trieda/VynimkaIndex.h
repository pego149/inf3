#pragma once
#include <string>
#include <iostream>

using namespace std;

class VynimkaIndex
{
	int aIndex;
	string aOznam;
public:
	VynimkaIndex(string poznam, int pIndex)
		:aOznam(poznam), aIndex(pIndex) {}
	int getIndex() const { return aIndex; }
	string getOznam() const { return aOznam; }
};

class VynimkaDolnyIndex :
	public VynimkaIndex
{
public:
	VynimkaDolnyIndex(int pindex)
		:VynimkaIndex("Dolny index mimo hranic", pindex) 
	{
		//cout << "Dolny index mimo hranic:" << pindex << endl;
	}
};

class VynimkaHornyIndex :
	public VynimkaIndex
{
public:
	VynimkaHornyIndex(int pindex)
		:VynimkaIndex("Horny index mimo hranic", pindex) 
	
	{
		//cout << "Horny index mimo hranic:" << pindex << endl;
	}
};

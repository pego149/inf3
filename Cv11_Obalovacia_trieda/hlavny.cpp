#include "Klient.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{
		Klient klient;
	}
	catch (...)
	{
		cerr << "Neznama vynimka" << endl;
	}
	return 0;
}
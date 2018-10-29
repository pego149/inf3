#ifdef _DEBUG
#include "test.h"
#endif // _DEBUG
#include <iostream>
#include "sifrator.h"

using namespace std;

int main(int argc, char *argv[]) {
	bool ok = true;
#ifdef _DEBUG
	Test test;
	ok = test.testuj();
#endif // _DEBUG
	if (ok) //ked pojde tak zmenit na ok
	{
		//beh hlavneho programu
		char cinnost = 'h';
		char* heslo = nullptr;
		char* vstupnySubor = nullptr;
		bool konzola = true;
		char* vystupnySubor = nullptr;
		if (argc > 1)
		{
			cinnost = argv[1][0];
		}
		if (argc > 2)
		{
			heslo = argv[2];
		}
		if (argc > 3)
		{
			vstupnySubor = argv[3];
		}
		if (argc > 4)
		{
			konzola = argv[4][0] == 's' ? false : true;
		}
		if (argc > 5)
		{
			vystupnySubor = argv[5];
		}
		Sifrator(cinnost, heslo, vstupnySubor, konzola, vystupnySubor).Start();
	}
	else
	{
		cout << "TESTY NEPRESLI";
	}

	return 0;
}
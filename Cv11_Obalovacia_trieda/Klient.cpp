#include "Klient.h"
#include "VynimkaIndex.h"


Klient::Klient()
	:aPole(new Pole<double>(-3, 20, 0))
{
	int hi(200), di(-100);
	bool opakuj(true);
	do
	{
		try
		{
			opakuj = false;
			(*aPole)[hi] = (*aPole)[di];
		}
		catch (VynimkaDolnyIndex ex)
		{
			cout << ex.getOznam() << " di=" << di << ", dinew=" << ex.getIndex() << endl;
			di = ex.getIndex();
			opakuj = true;
		}
		catch (VynimkaHornyIndex ex)
		{
			cout << ex.getOznam() << " hi=" << hi << ", hinew=" << ex.getIndex() << endl;
			hi = ex.getIndex();
			opakuj = true;
		}
	} while (opakuj);
	aPole->vypis();

}


Klient::~Klient()
{
	delete aPole;
}

#include "Klient.h"
#include "VynimkaIndex.h"
#include "ILogger.h"

Klient::Klient()
	:aPole(new Pole<double>(-3, 20, 0))
{
	int hi(200), di(-100);
	bool opakuj(true);
	logger->Log(DEBUG, "Start konstruktora klienta");
	do
	{
		try
		{
			logger->Log(DEBUG, "Nastavenie prvku s indexom -3 na hodnotu 10.2");
			(*aPole)[-3] = 10.2;
			logger->Log(DEBUG, "Nastavenie prvku s najvyssim indexom na hodnotu prvku s najnizsim");
			(*aPole)[hi] = (*aPole)[di];
			logger->Log(DEBUG, "Vypis prvkov pola");
			aPole->vypis();
			opakuj = false;
		}
		catch (VynimkaDolnyIndex &ex)
		{
			//cout << ex.getOznam() << " di=" << di << ", dinew=" << ex.getIndex() << endl;
			di = ex.getIndex();
			logger->Log(ERROR, ex.getOznam().c_str());
			opakuj = true;
		}
		catch (VynimkaHornyIndex &ex)
		{
			//cout << ex.getOznam() << " hi=" << hi << ", hinew=" << ex.getIndex() << endl;
			hi = ex.getIndex();
			logger->Log(ERROR, ex.getOznam().c_str());
			opakuj = true;
		}
		catch (VynimkaIndex &ex)
		{
			logger->Log(ERROR, ex.getOznam().c_str());
		}
	} while (opakuj);

}


Klient::~Klient()
{
	logger->Log(DEBUG, "Dealokacia pola v destruktore Klient");
	delete aPole;
}

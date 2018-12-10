#include "Klient.h"
#include <iostream>
#include "StreamLogger.h"
#include "CompositeLogger.h"

using namespace std;

//ILogger* logger = new StreamLogger("C:\\temp\\pole.log");
ILogger* logger = new CompositeLogger();

int main()
{
	try
	{
		logger->Log(INFO, "Start programu");
		Klient klient;
		logger->Log(INFO, "Koniec programu");
	}
	catch (...)
	{
		cerr << "Neznama vynimka" << endl;
	}
	return 0;
}
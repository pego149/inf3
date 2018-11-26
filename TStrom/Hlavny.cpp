#include "Strom.h"
#include "StringStrom.h"
#include <string>
typedef Strom<string> SStrom;

int main() 
{
	SStrom bstrom;
	bstrom.vloz("v");
	bstrom.vloz("rwrt");
	bstrom.vloz("iop");
	bstrom.vloz("qwqe");
	bstrom.vloz("1213");
	bstrom.vloz("opi");
	bstrom.vypis();

	StringStrom strbstrom;

	string x("aaa");
	return 0;
}
#include "zoznam.h"

int main() {
	Zoznam zoznam;
	zoznam.sort("data.txt", porovnaj);
	zoznam.uloz("utriedeny.txt");
	zoznam.uloz(nullptr);
	return 0;
}
//dorobit ze bude vypisovat na konzolu a do suboru len parne cisla
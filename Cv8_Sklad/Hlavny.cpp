#include "sklad.h"

int main() {
	Sklad sklad;
	sklad.pridaj("A", 10, 3);
	sklad.pridaj("B", 100, 20);
	sklad.pridaj("C", 10, 5);
	sklad.zobrazPodlaNazov();
	sklad.zobrazPodlaCena();
	sklad.zobrazPodlaPocet();
	return 0;
}
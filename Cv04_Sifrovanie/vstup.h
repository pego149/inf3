#pragma once
class Vstup
{
private:
	char *aMenoSuboru;
	unsigned dajDlzkuSuboru();
public:
	Vstup(const char *menoSuboru);
	Vstup(const Vstup &zdroj);
	Vstup &operator =  (const Vstup &zdroj);
	~Vstup();

	unsigned char *citaj();
};


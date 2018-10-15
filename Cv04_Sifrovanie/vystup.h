#pragma once
class Vystup
{
private:
	char *aMenoSuboru;
public:
	Vystup(const char *menoSuboru);
	Vystup(const Vystup &zdroj);
	Vystup &operator = (const Vystup &zdroj);
	~Vystup();
	void zapis(unsigned char *text);
};


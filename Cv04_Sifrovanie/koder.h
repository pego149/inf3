#pragma once
const unsigned DLZKA_TABULKY = 256;
class Koder
{
private:
	unsigned char aKodTabulka[DLZKA_TABULKY];
	void zakodujTabulku(const unsigned char *heslo);
	void dekodujTabulku();
	unsigned DajNasadu(const unsigned char *heslo);
	void vymen(unsigned char &a, unsigned char &b);
	void vymen(unsigned char *a, unsigned char *b);
public:
	Koder();
	~Koder();

	unsigned char *koduj(const unsigned char *heslo, const unsigned char *text);
	unsigned char *dekoduj(const unsigned char *heslo, const unsigned char *sifrtext);
};


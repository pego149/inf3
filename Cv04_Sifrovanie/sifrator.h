#pragma once
class Sifrator
{
private:
	char aCinnost; //typ pozadovanej cinnosti: s - sifrovanie, d - desifrovanie, h - help
	char *aHeslo; // heslo max 8 znakov
	char *aVstupnySubor; // meno vratane cesty
	bool aKonzola; //Indikator vypisu na konzolu
	char *aVystupnySubor; // meno vratane cesty
	void init(char cinnost, const char *heslo, const char *vstupSubor, bool konzola, const char *vystupSubor);
	void zmaz();
	void vypisHelp();//NA DOMACU ULOHU
public:
	Sifrator(char cinnost, const char *heslo, const char *vstupSubor, bool konzola, const char *vystupSubor);
	Sifrator(const Sifrator &zdroj);
	Sifrator &operator = (const Sifrator &zdroj);
	~Sifrator();

	void Start();
};


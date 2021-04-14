#ifndef KSIAZKAADRESOWA_HH
#define KSIAZKAADRESOWA_HH

#include <iostream>
#include "uzytkownikMenager.h"
#include "adresatMenager.h"

using namespace std;

class KsiazkaAdresowa {

	UzytkownikMenager uzytkownikMenager;
	AdresatMenager *adresatMenager;
	const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
		: uzytkownikMenager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
	{
		adresatMenager = NULL;
	};

	~KsiazkaAdresowa()
	{
		delete adresatMenager;
		adresatMenager = NULL;
	}

	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void logowanieUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wylogowanieUzytkownika();
	void dodajAdresata();
	void wyswietlWszystkichAdesatow();
	bool czyUzytkownikJestZalogowany();
	void usunAdresata();
	void edytujAdresata();	
};

#endif

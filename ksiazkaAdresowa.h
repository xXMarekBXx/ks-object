#ifndef KSIAZKAADRESOWA_HH
#define KSIAZKAADRESOWA_HH

#include <iostream>
#include "uzytkownikMenager.h"
#include "adresatMenager.h"

using namespace std;

class KsiazkaAdresowa {

	UzytkownikMenager uzytkownikMenager;
	AdresatMenager *adresatMenager;

public:
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenager(nazwaPlikuZUzytkownikami) {
		uzytkownikMenager.wczytajUzytkownikowZPliku();
		adresatMenager = NULL;
	};

	~KsiazkaAdresowa()
	{
		delete adresatMenager;
		adresatMenager = NULL;
	}

	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void wczytajUzytkownikowZPliku();
	void logowanieUzytkownika();
	void wylogowanieUzytkownika();
	bool czyUzytkownikJestZalogowany();
	void zmianaHaslaZalogowanegoUzytkownika();
	void dodajAdresata();
	void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
};

#endif

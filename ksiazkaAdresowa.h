#ifndef KSIAZKAADRESOWA_HH
#define KSIAZKAADRESOWA_HH

#include <iostream>
#include "uzytkownikMenager.h"

using namespace std;

class KsiazkaAdresowa {

	UzytkownikMenager uzytkownikMenager;

public:
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenager(nazwaPlikuZUzytkownikami) {
		uzytkownikMenager.wczytajUzytkownikowZPliku();
	};
	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void wczytajUzytkownikowZPliku();
	void logowanieUzytkownika();
	void wylogowanieUzytkownika();
	bool czyUzytkownikJestZalogowany();
	void zmianaHaslaZalogowanegoUzytkownika();
};

#endif

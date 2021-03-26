#ifndef KSIAZKAADRESOWA_HH
#define KSIAZKAADRESOWA_HH

#include <iostream>
#include "uzytkownikMenager.h"
#include "adresatMenager.h"

using namespace std;

class KsiazkaAdresowa {

	UzytkownikMenager uzytkownikMenager;
	AdresatMenager adresatMenager;

public:
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenager(nazwaPlikuZUzytkownikami) {
		uzytkownikMenager.wczytajUzytkownikowZPliku();				
	};
	
	/*

	Takie pomys³y przychodzi³y mi do g³owy:

	adresatMenager.wczytajAdresatowZalogowanegoUzytkownikaZPliku();

	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : adresatMenager(nazwaPlikuZUzytkownikami) {
		adresatMenager.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
	};
	*/


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

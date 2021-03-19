#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

#include <iostream>
#include <vector>
#include <string>
#include "uzytkownik.h"
#include "adresat.h"
#include "plikZUzytkownikami.h"
#include "plikZAdresatami.h"

using namespace std;

class UzytkownikMenager {

	int idZalogowanegoUzytkownika;
	vector <Uzytkownik> uzytkownicy;
	vector <Adresat> adresaci;
	
	Uzytkownik podajDaneNowegoUzytkownika();
	Adresat podajDaneNowegoAdresata(int idOstatniegoAdresata);
	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);
	PlikZUzytkownikami plikZUzytkownikami;
	PlikZAdresatami plikZAdresatami;


public:	
	UzytkownikMenager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
		uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
	};

	UzytkownikMenager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {
		adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
	};

	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void wczytajUzytkownikowZPliku();
	int logowanieUzytkownika();
	int wylogowanieUzytkownika();
	bool czyUzytkownikJestZalogowany();
	void zmianaHaslaZalogowanegoUzytkownika();
	int dodajAdresata(int idOstatniegoAdresata);
};

#endif
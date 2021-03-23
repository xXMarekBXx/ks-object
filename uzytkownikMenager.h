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
	
	Uzytkownik podajDaneNowegoUzytkownika();
	
	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);
	PlikZUzytkownikami plikZUzytkownikami;

public:	
	UzytkownikMenager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
		uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
	};

	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void wczytajUzytkownikowZPliku();
	int logowanieUzytkownika();
	int wylogowanieUzytkownika();
	bool czyUzytkownikJestZalogowany();
	void zmianaHaslaZalogowanegoUzytkownika();

};

#endif
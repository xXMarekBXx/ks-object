#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "uzytkownik.h"
#include "adresat.h"
#include "plikZUzytkownikami.h"

using namespace std;

class UzytkownikMenager {

	int idZalogowanegoUzytkownika;
	vector <Uzytkownik> uzytkownicy;
	PlikZUzytkownikami plikZUzytkownikami;
	
	Uzytkownik podajDaneNowegoUzytkownika();	
	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);	

public:	
	UzytkownikMenager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
		idZalogowanegoUzytkownika = 0;
		uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
	};

	int pobierzIdZalogowanegoUzytkownika();
	void rejestracjaUzytkownika();
	int logowanieUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	int wylogowanieUzytkownika();
	bool czyUzytkownikJestZalogowany();
	void wypiszWszystkichUzytkownikow();
	//void wczytajUzytkownikowZPliku();	
};

#endif
#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

#include <iostream>
#include <vector>
#include <string>
#include "uzytkownik.h"
#include "plikZUzytkownikami.h"

using namespace std;

class UzytkownikMenager {

	int idZalogowanegoUzytkownika;
	vector <Uzytkownik> uzytkownicy;

	Uzytkownik podajDaneNowegoUzytkownika();
	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);
	PlikZUzytkownikami plikZUzytkownikami;

public:
	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
};

#endif
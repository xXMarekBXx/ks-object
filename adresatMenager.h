#ifndef ADRESATMENAGER_H
#define ADRESATMENAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "adresat.h"
#include "plikZAdresatami.h"

using namespace std;

class AdresatMenager {

	const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
	vector <Adresat> adresaci;
	PlikZAdresatami plikZAdresatami;
		
	Adresat podajDaneNowegoAdresata();
	void wyswietlDaneAdresata(Adresat adresat);
	
public:
	AdresatMenager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
		: plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
	{
		adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
	};
	void dodajAdresata();
	void wyswietlWszystkichAdresatow();
};

#endif
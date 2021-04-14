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

	const string NAZWA_PLIKU_Z_ADRESATAMI;
	const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;
		
	Adresat podajDaneNowegoAdresata();
	void wyswietlDaneAdresata(Adresat adresat);
	int podajIdWybranegoAdresata();
	int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
	
public:
	AdresatMenager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
		: plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
	{
		adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
	};
	void dodajAdresata();
	void wyswietlWszystkichAdresatow();
	int usunAdresata();//vector <Adresat> &adresaci
	int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);
};

#endif
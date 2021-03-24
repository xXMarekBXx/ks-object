#ifndef ADRESATMENAGER_H
#define ADRESATMENAGER_H

#include <iostream>
#include <vector>
#include <string>
#include "uzytkownik.h"
#include "adresat.h"
#include "plikZAdresatami.h"

using namespace std;

class AdresatMenager {

	int idZalogowanegoUzytkownika;	
	vector <Adresat> adresaci;
		
	Adresat podajDaneNowegoAdresata(int idOstatniegoAdresata);
	PlikZAdresatami plikZAdresatami; // PlikZAdresatami plikZAdresatami(string ksiazka_adresowa) {}; ??? Jak to naprawiæ?


public:

	AdresatMenager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {
		adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
	};

	int dodajAdresata();
};

#endif
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
	PlikZAdresatami plikZAdresatami;
	
public:
	AdresatMenager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {
		adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
	};

	Adresat dodajAdresata();
	void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
};

#endif
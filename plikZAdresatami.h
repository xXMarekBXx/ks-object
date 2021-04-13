#ifndef PLIKZUZADRESATAMI_H
#define PLIKZUZADRESATAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <string>
#include "adresat.h"
#include "metodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {

	const string NAZWA_PLIKU_Z_ADRESATAMI;
	int idOstatniegoAdresata;

	vector <Adresat> adresaci;
	Adresat adresat;

	string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
	bool czyPlikJestPusty(fstream &plikTekstowy);
	string pobierzLiczbe(string tekst, int pozycjaZnaku);	
	Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
	int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:
	PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
		idOstatniegoAdresata = 0;
	};
	bool dopiszAdresataDoPliku(Adresat adresat);
	string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
	vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	int pobierzIdOstatniegoAdresata();
};

#endif
#ifndef PLIKZUZADRESATAMI_H
#define PLIKZUZADRESATAMI_H

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "adresat.h"
#include "metodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {

	const string nazwaPlikuZAdresatami;

	vector <Adresat> adresaci;
	Adresat adresat;

	int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);	
	int idZalogowanegoUzytkownika;

public:
	PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {};

	vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku();
	Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
	int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	void dopiszAdresataDoPliku();
};

#endif
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
#include "adresatMenager.h"

using namespace std;

class PlikZAdresatami {

	const string nazwaPlikuZAdresatami;

	vector <Adresat> adresaci;
	Adresat adresat;

	int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);	
	static int idZalogowanegoUzytkownika;

public:
	PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {};
	PlikZAdresatami() {};

	static int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
	static Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
	static int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	static void dopiszAdresataDoPliku();
};

#endif
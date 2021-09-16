#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include "uzytkownik.h"
#include "adresat.h"
#include "metodyPomocnicze.h"

using namespace std;

class PlikTekstowy {

	const string NAZWA_PLIKU = "Adresaci.txt";

public:

	PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {}

	string pobierzNazwePliku();
	bool czyPlikJestPusty();
};

#endif

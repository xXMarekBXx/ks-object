#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "uzytkownik.h"
#include "metodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami {

	string nazwaPlikuZUzytkownikami;
	fstream plikTekstowy;

	vector <Uzytkownik> uzytkownicy;

	bool czyPlikJestPusty();
	string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

public:
	PlikZUzytkownikami();
	void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
	void wczytajUzytkownikowZPliku();
	Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
};

#endif
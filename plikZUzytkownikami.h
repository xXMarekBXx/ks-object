#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "uzytkownik.h"
#include "metodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami {

	const string nazwaPlikuZUzytkownikami;	

	vector <Uzytkownik> uzytkownicy;
	
	bool czyPlikJestPusty();
	string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
	Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
	
public:
	PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI) : nazwaPlikuZUzytkownikami(NAZWAPLIKUZUZYTKOWNIKAMI) {};
	void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
	vector <Uzytkownik> wczytajUzytkownikowZPliku();
};

#endif
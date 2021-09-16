#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include "uzytkownik.h"
#include "metodyPomocnicze.h"
#include "plikTekstowy.h"


using namespace std;

class PlikZUzytkownikami : public PlikTekstowy {

	//const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;

	string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
	//bool czyPlikJestPusty(fstream &plikTekstowy);
	Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
	PlikZUzytkownikami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
	/*
public:
	PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami) {};
	*/
	void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
	vector <Uzytkownik> wczytajUzytkownikowZPliku();
	void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);	
};

#endif
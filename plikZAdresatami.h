#ifndef PLIKZUZADRESATAMI_H
#define PLIKZUZADRESATAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdio>
#include "adresat.h"
#include "metodyPomocnicze.h"
#include "plikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy {

	//const string NAZWA_PLIKU_Z_ADRESATAMI;
	const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI = "tymczasowy.txt";
	int idOstatniegoAdresata;

	vector <Adresat> adresaci;
	Adresat adresat;
		
	//bool czyPlikJestPusty(fstream &plikTekstowy);
	string pobierzLiczbe(string tekst, int pozycjaZnaku);	
	Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
	
	void usunPlik(string nazwaPlikuZRozszerzeniem);
	void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
	PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {
		idOstatniegoAdresata = 0;
	};
	/*
public:
	PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
		idOstatniegoAdresata = 0;
	};
	*/
	string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
	int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	bool dopiszAdresataDoPliku(Adresat adresat);
	string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
	vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	int pobierzIdOstatniegoAdresata();
	void usunWybranaLinieWPliku(int numerUsuwanejLinii);
	int pobierzZPlikuIdOstatniegoAdresata();
	void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
	void usunWybranegoAdresataZPliku(int idUsunietegoAdresata);
	int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);
	void ustawIdOstatniegoAdresata(int noweId);
};

#endif
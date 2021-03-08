#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "plikZUzytkownikami.h"

using namespace std;

PlikZUzytkownikami::PlikZUzytkownikami() {

	nazwaPlikuZUzytkownikami = "Uzytkownicy.txt";
}

bool PlikZUzytkownikami::czyPlikJestPusty()
{
	plikTekstowy.seekg(0, ios::end);
	if (plikTekstowy.tellg() == 0)
		return true;
	else
		return false;
}

void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
	string liniaZDanymiUzytkownika = "";
	plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::app);

	if (plikTekstowy.good() == true)
	{
		liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

		if (czyPlikJestPusty() == true)
		{
			plikTekstowy << liniaZDanymiUzytkownika;
		}
		else
		{
			plikTekstowy << endl << liniaZDanymiUzytkownika;
		}
	}
	else
		cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac w nim danych." << endl;
	plikTekstowy.close();
}


string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
	string liniaZDanymiUzytkownika = "";
	
	liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId()) + '|';
	liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
	liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

	return liniaZDanymiUzytkownika;
}
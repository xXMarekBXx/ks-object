#ifndef KSIAZKAADRESOWA_HH
#define KSIAZKAADRESOWA_HH

#include <iostream>
#include <vector>
#include <string>
#include "uzytkownik.h"

using namespace std;

class KsiazkaAdresowa {	

	int idZalogowanegoUzytkownika;
	int idOstatniegoAdresata;
	int idUsunietegoAdresata;

	string nazwaPlikuZUzytkownikami;

	vector <Uzytkownik> uzytkownicy;

	Uzytkownik podajDaneNowegoUzytkownika();
	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);
	void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
	string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
	string konwerjsaIntNaString(int liczba);
	bool czyPlikJestPusty(fstream &plikTekstowy);

public:
	KsiazkaAdresowa();
	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
};







#endif

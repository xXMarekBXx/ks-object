#ifndef KSIAZKAADRESOWA_HH
#define KSIAZKAADRESOWA_HH

#include <iostream>
#include "uzytkownikMenager.h"

using namespace std;

class KsiazkaAdresowa {	
		
	UzytkownikMenager uzytkownikMenager;
	PlikZUzytkownikami plikZUzytkownikami;

public:
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenager(nazwaPlikuZUzytkownikami) {
		uzytkownikMenager.wczytajUzytkownikowZPliku();
	};
	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void wczytajUzytkownikowZPliku();
};

#endif

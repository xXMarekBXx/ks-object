#ifndef KSIAZKAADRESOWA_HH
#define KSIAZKAADRESOWA_HH

#include <iostream>
#include "uzytkownikMenager.h"

using namespace std;

class KsiazkaAdresowa {	
		
	UzytkownikMenager uzytkownikMenager;

public:

	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();

};

#endif

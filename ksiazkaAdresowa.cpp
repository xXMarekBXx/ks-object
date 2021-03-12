#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include "ksiazkaAdresowa.h"
#include "plikZUzytkownikami.h"

using namespace std;

void KsiazkaAdresowa::rejestracjaUzytkownika() {
	uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
	uzytkownikMenager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::wczytajUzytkownikowZPliku() {
	uzytkownikMenager.wczytajUzytkownikowZPliku();
}

int KsiazkaAdresowa::logowanieUzytkownika() {
	uzytkownikMenager.logowanieUzytkownika();
	return 0;
}
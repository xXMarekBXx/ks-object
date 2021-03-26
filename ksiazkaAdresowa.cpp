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

void KsiazkaAdresowa::logowanieUzytkownika() {	
	uzytkownikMenager.logowanieUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
	uzytkownikMenager.wylogowanieUzytkownika();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {
	if (uzytkownikMenager.czyUzytkownikJestZalogowany() == true)
		return true;
	else
		return false;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
	uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
	adresatMenager.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::dodajAdresata() {
	adresatMenager.dodajAdresata();
}
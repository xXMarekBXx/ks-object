#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
	uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
	uzytkownikMenager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
	uzytkownikMenager.logowanieUzytkownika();
	if (uzytkownikMenager.czyUzytkownikJestZalogowany())
	{
		adresatMenager = new AdresatMenager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());
	}
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
	uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
	uzytkownikMenager.wylogowanieUzytkownika();
	delete adresatMenager;
	adresatMenager = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
	if (uzytkownikMenager.czyUzytkownikJestZalogowany())
	{
		adresatMenager->dodajAdresata();
	}
	else
	{
		cout << "Aby dodac adresata , nalezy najpierw sie zalogowac" << endl;
		system("pause");
	}
}

void KsiazkaAdresowa::wyswietlWszystkichAdesatow()
{
	if (uzytkownikMenager.czyUzytkownikJestZalogowany())
	{
		adresatMenager->wyswietlWszystkichAdresatow();
	}
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
	if (uzytkownikMenager.czyUzytkownikJestZalogowany() > 0)
		return true;
	else
		return false;

}
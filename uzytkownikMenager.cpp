#include <iostream>
#include <vector>
#include <string>
#include "uzytkownikMenager.h"

using namespace std;

Uzytkownik UzytkownikMenager::podajDaneNowegoUzytkownika() {

	Uzytkownik uzytkownik;

	uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

	string login;

	do
	{
		cout << "Podaj login: ";
		cin >> login;

		uzytkownik.ustawLogin(login);

	} while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

	cout << "Podaj haslo: ";
	string haslo;
	cin >> haslo;
	uzytkownik.ustawHaslo(haslo);

	return uzytkownik;
}

int  UzytkownikMenager::pobierzIdNowegoUzytkownika() {

	if (uzytkownicy.empty() == true)
		return 1;
	else
		return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenager::czyIstniejeLogin(string login) {

	int dlugoscWektoraUzytkownicy = uzytkownicy.size();

	for (int i = 0; i < dlugoscWektoraUzytkownicy; i++) {
		if (uzytkownicy[i].pobierzLogin() == login)
		{
			cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
			return true;
		}
	}
	return false;
}

void UzytkownikMenager::rejestracjaUzytkownika() {

	Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
	
	uzytkownicy.push_back(uzytkownik);
	plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

	cout << "Konto zalozono pomyslnie" << endl << endl;
	system("pause");
}

void UzytkownikMenager::wypiszWszystkichUzytkownikow() {
	int dlugoscWektoraUzytkownicy = uzytkownicy.size();

	for (int i = 0; i < dlugoscWektoraUzytkownicy; i++) {

		cout << uzytkownicy[i].pobierzId() << endl;
		cout << uzytkownicy[i].pobierzLogin() << endl;
		cout << uzytkownicy[i].pobierzHaslo() << endl;
	}
}

void UzytkownikMenager::wczytajUzytkownikowZPliku() {
	plikZUzytkownikami.wczytajUzytkownikowZPliku();
}
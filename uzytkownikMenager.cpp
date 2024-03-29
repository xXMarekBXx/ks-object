#include "uzytkownikMenager.h"

int UzytkownikMenager::pobierzIdZalogowanegoUzytkownika()
{
	return idZalogowanegoUzytkownika;
}

void UzytkownikMenager::rejestracjaUzytkownika() {

	Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

	uzytkownicy.push_back(uzytkownik);
	plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

	cout << "Konto zalozono pomyslnie" << endl << endl;
	system("pause");
}

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

void UzytkownikMenager::wypiszWszystkichUzytkownikow() {
	int dlugoscWektoraUzytkownicy = uzytkownicy.size();

	for (int i = 0; i < dlugoscWektoraUzytkownicy; i++) {

		cout << uzytkownicy[i].pobierzId() << endl;
		cout << uzytkownicy[i].pobierzLogin() << endl;
		cout << uzytkownicy[i].pobierzHaslo() << endl;
	}
}

bool UzytkownikMenager::czyUzytkownikJestZalogowany()
{
	if (idZalogowanegoUzytkownika > 0)
		return true;
	else
		return false;
}

int UzytkownikMenager::logowanieUzytkownika() {

	Uzytkownik uzytkownik;
	string login = "", haslo = "";

	cout << endl << "Podaj login: ";	
	cin >> login;

	vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
	while (itr != uzytkownicy.end())
	{
		if (itr->pobierzLogin() == login)
		{
			for (int iloscProb = 3; iloscProb > 0; iloscProb--)
			{
				cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
				cin >> haslo;

				if (itr->pobierzHaslo() == haslo)
				{
					cout << endl << "Zalogowales sie." << endl << endl;
					system("pause");
					idZalogowanegoUzytkownika = itr->pobierzId();
					return idZalogowanegoUzytkownika;
				}
			}
			cout << "Wprowadzono 3 razy bledne haslo." << endl;
			system("pause");
			return 0;
		}
		itr++;
	}
	cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
	system("pause");
	return 0;
}

void UzytkownikMenager::zmianaHaslaZalogowanegoUzytkownika()
{
	Uzytkownik uzytkownik;

	string noweHaslo = "";

	cout << "Podaj nowe haslo: ";

	cin >> noweHaslo;
		
	for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
	{
		if (itr->pobierzId() == idZalogowanegoUzytkownika)
		{
			itr->ustawHaslo(noweHaslo);
			cout << "Haslo zostalo zmienione." << endl << endl;
			system("pause");
		}
	}
	plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UzytkownikMenager::wylogowanieUzytkownika() {
	idZalogowanegoUzytkownika = 0;
	return idZalogowanegoUzytkownika;
}

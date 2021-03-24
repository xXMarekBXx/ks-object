#include <iostream>
#include <vector>
#include <string>
#include "adresatMenager.h"
#include "plikZAdresatami.h"

using namespace std;

Adresat AdresatMenager::dodajAdresata() {

	Adresat adresat;

	vector <Adresat> idOstatniegoAdresata = PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku();

	adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

	adresaci.push_back(adresat);
	PlikZAdresatami::dopiszAdresataDoPliku();

	//return ++idOstatniegoAdresata;
	return adresat;
}

Adresat AdresatMenager::podajDaneNowegoAdresata(int idOstatniegoAdresata)
{
	MetodyPomocnicze metodyPomocnicze;

	Adresat adresat;

	adresat.ustawId(++idOstatniegoAdresata);
	adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

	cout << "Podaj imie: ";
	string noweImie;
	cin >> noweImie;
	adresat.ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(noweImie));

	cout << "Podaj nazwisko: ";
	string noweNazwisko;
	cin >> noweNazwisko;
	adresat.ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(noweNazwisko));

	cout << "Podaj numer telefonu: ";
	string numerTelefonu;
	cin >> numerTelefonu;
	adresat.ustawNumerTelefonu(numerTelefonu);

	cout << "Podaj email: ";
	string email;
	cin >> email;
	adresat.ustawEmail(email);

	cout << "Podaj adres: ";
	string adres;
	cin >> adres;
	adresat.ustawAdres(adres);

	return adresat;
}
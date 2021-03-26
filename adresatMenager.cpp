#include <iostream>
#include <vector>
#include <string>
#include "adresatMenager.h"
#include "plikZAdresatami.h"

using namespace std;

void AdresatMenager::dodajAdresata() {

	Adresat adresat;

	vector <Adresat> idOstatniegoAdresata = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();

	adresat = podajDaneNowegoAdresata();

	adresaci.push_back(adresat);
	plikZAdresatami.dopiszAdresataDoPliku();

	//return ++idOstatniegoAdresata;
	//return adresat;
}

Adresat AdresatMenager::podajDaneNowegoAdresata() {
	MetodyPomocnicze metodyPomocnicze;

	Adresat adresat;

	adresat.ustawId((plikZAdresatami.pobierzIdOstatniegoAdresata() + 1));
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

void AdresatMenager::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
	plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}
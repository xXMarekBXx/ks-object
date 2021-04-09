#include "AdresatMenager.h"

void AdresatMenager::dodajAdresata()
{
	Adresat adresat;

	system("cls");
	cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
	adresat = podajDaneNowegoAdresata();

	adresaci.push_back(adresat);
	if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
		cout << "Nowy adresat zostal dodany" << endl;
	else
		cout << "Blad. Nie udalo sie dodac nowego adresata do pliku" << endl;
	system("pause");
}

Adresat AdresatMenager::podajDaneNowegoAdresata() {

	Adresat adresat;
	adresat.ustawId((plikZAdresatami.pobierzIdOstatniegoAdresata() + 1));
	adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

	string imie;
	cout << "Podaj imie: ";
	cin.ignore();
	imie = MetodyPomocnicze::wczytajLinie();
	imie = plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
	adresat.ustawImie(imie);

	string nazwisko;
	cout << "Podaj nazwisko: ";
	nazwisko = MetodyPomocnicze::wczytajLinie();
	nazwisko = plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
	adresat.ustawNazwisko(nazwisko);

	string numerTelefonu;
	cout << "Podaj numer telefonu: ";
	numerTelefonu = MetodyPomocnicze::wczytajLinie();
	numerTelefonu = plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(numerTelefonu);
	adresat.ustawNumerTelefonu(numerTelefonu);

	string email;
	cout << "Podaj email: ";
	email = MetodyPomocnicze::wczytajLinie();
	email = plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(email);
	adresat.ustawEmail(email);

	string adres;
	cout << "Podaj adres: ";
	adres = MetodyPomocnicze::wczytajLinie();
	adres = plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adres);
	adresat.ustawAdres(adres);

	return adresat;
}

void AdresatMenager::wyswietlWszystkichAdresatow()
{
	system("cls");
	if (!adresaci.empty())
	{
		cout << "             >>> ADRESACI <<<" << endl;
		cout << "-----------------------------------------------" << endl;
		for (vector <Adresat> ::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
		{
			wyswietlDaneAdresata(*itr);
		}
		cout << endl;
	}
	else
	{
		cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
	}
	system("pause");
}

void AdresatMenager::wyswietlDaneAdresata(Adresat adresat)
{
	cout << endl << "Id:                 " << adresat.pobierzId() << endl;
	cout << "Imie:               " << adresat.pobierzImie() << endl;
	cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
	cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
	cout << "Email:              " << adresat.pobierzEmail() << endl;
	cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
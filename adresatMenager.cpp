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

int AdresatMenager::usunAdresata()//vector <Adresat> &adresaci
{
	int idUsuwanegoAdresata = 0;
	int numerLiniiUsuwanegoAdresata = 0;

	system("cls");
	cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
	idUsuwanegoAdresata = podajIdWybranegoAdresata();

	char znak;
	bool czyIstniejeAdresat = false;

	for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
	{
		if (itr->pobierzId() == idUsuwanegoAdresata)
		{
			czyIstniejeAdresat = true;
			cout << endl << "Potwierdz naciskajac klawisz 't': ";
			znak = MetodyPomocnicze::wczytajZnak();
			if (znak == 't')
			{
				numerLiniiUsuwanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata);
				PlikZAdresatami::usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata);
				adresaci.erase(itr);
				cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
				system("pause");
				return idUsuwanegoAdresata;
			}
			else
			{
				cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
				system("p       ause");
				return 0;
			}
		}
	}
	if (czyIstniejeAdresat == false)
	{
		cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
		system("pause");
	}
	return 0;
}

int AdresatMenager::podajIdWybranegoAdresata()
{
	int idWybranegoAdresata = 0;
	cout << "Podaj numer ID Adresata: ";
	idWybranegoAdresata = MetodyPomocnicze::wczytajLiczbeCalkowita();
	return idWybranegoAdresata;
}

int AdresatMenager::zwrocNumerLiniiSzukanegoAdresata(int idAdresata)
{
	bool czyIstniejeAdresat = false;
	int numerLiniiWPlikuTekstowym = 1;
	string daneJednegoAdresataOddzielonePionowymiKreskami = "";
	fstream plikTekstowy;
	plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

	if (plikTekstowy.good() == true && idAdresata != 0)
	{
		while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
		{
			if (idAdresata == PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
			{
				czyIstniejeAdresat = true;
				plikTekstowy.close();
				return numerLiniiWPlikuTekstowym;
			}
			else
				numerLiniiWPlikuTekstowym++;
		}
		if (czyIstniejeAdresat = false)
		{
			plikTekstowy.close();
			return 0;
		}
	}
	return 0;
}

int AdresatMenager::podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata)
{
	if (idUsuwanegoAdresata == idOstatniegoAdresata)
		return PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata();
	else
		return idOstatniegoAdresata;
}


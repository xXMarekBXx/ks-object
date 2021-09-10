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
	adresat.ustawNumerTelefonu(numerTelefonu);

	string email;
	cout << "Podaj email: ";
	email = MetodyPomocnicze::wczytajLinie();	
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

int AdresatMenager::usunAdresata()
{
	int idUsuwanegoAdresata = 0;
	int numerLiniiUsuwanegoAdresata = 0;
	int idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegoAdresata();
		
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
				plikZAdresatami.usunWybranegoAdresataZPliku(idUsuwanegoAdresata);
				adresaci.erase(itr);				
				cout << endl << "Szukany adresat zostal USUNIETY" << endl << endl;				
				system("pause");				
				idOstatniegoAdresata  = plikZAdresatami.podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsuwanegoAdresata,idOstatniegoAdresata);
				plikZAdresatami.ustawIdOstatniegoAdresata(idOstatniegoAdresata);
				return idUsuwanegoAdresata;					
			}
			else
			{
				cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
				system("pause");
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
	
	if (plikTekstowy.good())
	{
		while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
		{
			if (idAdresata == plikZAdresatami.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
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
	else
		cout << "Plik nie istnieje" << endl;

	return 0;
}

void AdresatMenager::edytujAdresata()
{
	system("cls");
	Adresat adresat;
	int idEdytowanegoAdresata = 0;
	cout << "idEdytowanegoAdresata: " << idEdytowanegoAdresata << endl;
	int numerLiniiEdytowanegoAdresata = 0;
	string liniaZDanymiAdresata = "";

	cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;	
	idEdytowanegoAdresata = podajIdWybranegoAdresata();	

	char wybor;
	bool czyIstniejeAdresat = false;

	int rozmiarWektoraAdresaci = adresaci.size();

	for (int i = 0; i < rozmiarWektoraAdresaci; i++)
	{
		if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
		{
			czyIstniejeAdresat = true;
			wybor = wybierzOpcjeZMenuEdycja();

			switch (wybor)
			{
			case '1':
				cout << "Podaj nowe imie: ";
				adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
				adresaci[i].ustawImie(plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
				zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
				break;
			case '2':
				cout << "Podaj nowe nazwisko: ";
				adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
				adresaci[i].ustawNazwisko(plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
				zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
				break;
			case '3':
				cout << "Podaj nowy numer telefonu: ";
				adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
				zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
				break;
			case '4':
				cout << "Podaj nowy email: ";
				adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
				zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
				break;
			case '5':
				cout << "Podaj nowy adres zamieszkania: ";
				adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
				zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
				break;
			case '6':
				cout << endl << "Powrot do menu uzytkownika" << endl << endl;
				break;
			default:
				cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
				break;
			}
		}
	}
	if (czyIstniejeAdresat == false)
	{
		cout << endl << "Nie ma takiego adresata." << endl << endl;
	}
	system("pause");
}

char AdresatMenager::wybierzOpcjeZMenuEdycja()
{
	char wybor;

	cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
	cout << "---------------------------" << endl;
	cout << "Ktore dane zaktualizowac: " << endl;
	cout << "1 - Imie" << endl;
	cout << "2 - Nazwisko" << endl;
	cout << "3 - Numer telefonu" << endl;
	cout << "4 - Email" << endl;
	cout << "5 - Adres" << endl;
	cout << "6 - Powrot " << endl;
	cout << endl << "Twoj wybor: ";
	wybor = MetodyPomocnicze::wczytajZnak();

	return wybor;
}

void AdresatMenager::zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata)
{
	int numerLiniiEdytowanegoAdresata = 0;	
	string liniaZDanymiAdresata = "";

	numerLiniiEdytowanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idEdytowanegoAdresata);
	liniaZDanymiAdresata = plikZAdresatami.zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
	plikZAdresatami.edytujWybranaLinieWPliku(numerLiniiEdytowanegoAdresata, liniaZDanymiAdresata);

	cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}


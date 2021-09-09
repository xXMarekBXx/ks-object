#include "PlikZAdresatami.h"

void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
	bool czyUdaloSieUsunacPlik = false;

	if (remove(nazwaPlikuZRozszerzeniem.c_str()))
	{
		czyUdaloSieUsunacPlik = true;		
	}
	if (czyUdaloSieUsunacPlik = true)
		cout << endl << "Plik " << nazwaPlikuZRozszerzeniem << " zostal usuniety" << endl;
	else
		cout << endl << "Nie udalo sie usunac pliku" << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
	bool czyUdaloSieZmienicNazwePliku = false;

	if (rename(staraNazwa.c_str(), nowaNazwa.c_str()))
	{
		czyUdaloSieZmienicNazwePliku = true;
	}

	if (czyUdaloSieZmienicNazwePliku = true)	
		cout << "Nazwa pliku " << staraNazwa << " zostala zmieniona na " << nowaNazwa << endl;	
	else
		cout << "Nazwa pliku " << staraNazwa << " nie zostala zmieniona."  << endl;
}

string PlikZAdresatami::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
	if (!tekst.empty())
	{
		transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
		tekst[0] = toupper(tekst[0]);
	}
	return tekst;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
	string liniaZDanymiAdresata = "";
	fstream plikTekstowy;
	plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

	if (plikTekstowy.good() == true)
	{
		liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

		if (czyPlikJestPusty(plikTekstowy) == true)
		{
			plikTekstowy << liniaZDanymiAdresata;
		}
		else
		{
			plikTekstowy << endl << liniaZDanymiAdresata;
		}
		idOstatniegoAdresata++;
		plikTekstowy.close();
		return true;
	}
	return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
	string liniaZDanymiAdresata = "";

	liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzId()) + '|';
	liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
	liniaZDanymiAdresata += adresat.pobierzImie() + '|';
	liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
	liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
	liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
	liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

	return liniaZDanymiAdresata;
}

bool PlikZAdresatami::czyPlikJestPusty(fstream &plikTekstowy)
{
	plikTekstowy.seekg(0, ios::end);
	if (plikTekstowy.tellg() == 0)
		return true;
	else
		return false;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
	vector <Adresat> adresaci;
	Adresat adresat;
	string daneJednegoAdresataOddzielonePionowymiKreskami = "";
	string daneOstaniegoAdresataWPliku = "";
	fstream plikTekstowy;
	plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

	if (plikTekstowy.good() == true)
	{
		while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
		{			
			if (idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
			{
				adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
				adresaci.push_back(adresat);
			}
		}
		daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
		plikTekstowy.close();
	}
	else
		cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

	plikTekstowy.close();

	if (daneOstaniegoAdresataWPliku != "")
	{
		idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
	}
	return adresaci;

}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
	Adresat adresat;
	string pojedynczaDanaAdresata = "";
	int numerPojedynczejDanejAdresata = 1;

	int dlugoscDanychOddzielonychPionowymiKreskami = daneAdresataOddzielonePionowymiKreskami.length();

	for (int pozycjaZnaku = 0; pozycjaZnaku < dlugoscDanychOddzielonychPionowymiKreskami; pozycjaZnaku++)
	{
		if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
		{
			pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
		}
		else
		{
			switch (numerPojedynczejDanejAdresata)
			{
			case 1:
				adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
				break;
			case 2:
				adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
				break;
			case 3:
				adresat.ustawImie(pojedynczaDanaAdresata);
				break;
			case 4:
				adresat.ustawNazwisko(pojedynczaDanaAdresata);
				break;
			case 5:
				adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
				break;
			case 6:
				adresat.ustawEmail(pojedynczaDanaAdresata);
				break;
			case 7:
				adresat.ustawAdres(pojedynczaDanaAdresata);
				break;
			}
			pojedynczaDanaAdresata = "";
			numerPojedynczejDanejAdresata++;
		}
	}
	return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
	int pozycjaRozpoczeciaIdAdresata = 0;
	int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
	return idAdresata;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
	int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of("|") + 1;
	int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));
	return idUzytkownika;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
	string liczba = "";
	while (isdigit(tekst[pozycjaZnaku]))
	{
		liczba += tekst[pozycjaZnaku];
		pozycjaZnaku++;
	}
	return liczba;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
	return idOstatniegoAdresata;
}

void PlikZAdresatami::ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata)
{	
	idOstatniegoAdresata = noweIdOstatniegoAdresata;
}

void PlikZAdresatami::usunWybranaLinieWPliku(int numerUsuwanejLinii)
{
	fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
	string wczytanaLinia = "";
	int numerWczytanejLinii = 1;	

	odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
	tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);
		
	if (odczytywanyPlikTekstowy.good() == true)
	{
		while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
		{
			// Tych przypadkow jest tyle, gdyz chcemy osiagnac taki efekt,
			// aby na koncu pliku nie bylo pustej linii
			if (numerWczytanejLinii == numerUsuwanejLinii) {}
			else if (numerWczytanejLinii == 1 && numerWczytanejLinii != numerUsuwanejLinii)
				tymczasowyPlikTekstowy << wczytanaLinia;
			else if (numerWczytanejLinii == 2 && numerUsuwanejLinii == 1)
				tymczasowyPlikTekstowy << wczytanaLinia;
			else if (numerWczytanejLinii > 2 && numerUsuwanejLinii == 1)
				tymczasowyPlikTekstowy << endl << wczytanaLinia;
			else if (numerWczytanejLinii > 1 && numerUsuwanejLinii != 1)
				tymczasowyPlikTekstowy << endl << wczytanaLinia;
			numerWczytanejLinii++;
		}
		odczytywanyPlikTekstowy.close();
		tymczasowyPlikTekstowy.close();

		usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);		
		zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);
	}
}

void PlikZAdresatami::usunWybranegoAdresataZPliku(int idUsunietegoAdresata) {
	fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
	string wczytanaLinia = "";
	int numerWczytanejLinii = 1;
	int idAdresataPobranegoZPliku = 0;
	
	odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
	tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);
		
	if (odczytywanyPlikTekstowy.good() == true) {	
		
		while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {			
			idAdresataPobranegoZPliku = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
			
			if (idUsunietegoAdresata == idAdresataPobranegoZPliku) {}			
			else if (numerWczytanejLinii == 1 && idUsunietegoAdresata != 1)
				tymczasowyPlikTekstowy << wczytanaLinia;
			else if (numerWczytanejLinii == 2 && idUsunietegoAdresata == 1)
				tymczasowyPlikTekstowy << wczytanaLinia;
			else if (numerWczytanejLinii > 2 && idUsunietegoAdresata == 1)
				tymczasowyPlikTekstowy << endl << wczytanaLinia;
			else if (numerWczytanejLinii > 1 && idUsunietegoAdresata != 1)
				tymczasowyPlikTekstowy << endl << wczytanaLinia;

			wczytanaLinia = "";
			idAdresataPobranegoZPliku = 0;
			numerWczytanejLinii++;
		}
	}
	
	odczytywanyPlikTekstowy.close();
	tymczasowyPlikTekstowy.close();

	usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
	zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);	
}

int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata()
{
	int idOstatniegoAdresata = 0;
	string daneJednegoAdresataOddzielonePionowymiKreskami = "";
	string daneOstaniegoAdresataWPliku = "";
	fstream plikTekstowy;
	plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

	if (plikTekstowy.good() == true)
	{
		while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
		daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
		plikTekstowy.close();
	}
	else
		cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

	if (daneOstaniegoAdresataWPliku != "")
	{
		idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
	}
	return idOstatniegoAdresata;
}

void PlikZAdresatami::edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami)
{
	fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
	string wczytanaLinia = "";
	int numerWczytanejLinii = 1;

	cout << "Numer wczytanej linii: " << numerWczytanejLinii << ", Numer edytowanej linii: " << numerEdytowanejLinii << endl;

	odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
	tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

	cout << "Numer wczytanej linii: " << numerWczytanejLinii << ", Numer edytowanej linii: " << numerEdytowanejLinii << endl;
		
	if (odczytywanyPlikTekstowy.good() == true)
	{
		cout << "Numer wczytanej linii: " << numerWczytanejLinii << ", Numer edytowanej linii: " << numerEdytowanejLinii << endl;
		while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
		{
			cout << "Numer wczytanej linii: " << numerWczytanejLinii << ", Numer edytowanej linii: " << numerEdytowanejLinii << endl;
			if (numerWczytanejLinii == numerEdytowanejLinii)
			{
				cout << "Numer wczytanej linii: " << numerWczytanejLinii << ", Numer edytowanej linii: " << numerEdytowanejLinii << endl;
				if (numerWczytanejLinii == 1)
					tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
				else if (numerWczytanejLinii > 1)
					tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
			}
			else
			{
				if (numerWczytanejLinii == 1)
					tymczasowyPlikTekstowy << wczytanaLinia;
				else if (numerWczytanejLinii > 1)
					tymczasowyPlikTekstowy << endl << wczytanaLinia;
			}
			numerWczytanejLinii++;
		}
		odczytywanyPlikTekstowy.close();
		tymczasowyPlikTekstowy.close();

		usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
		zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);
	}
}

int PlikZAdresatami::podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata)
{
	if (idUsuwanegoAdresata == idOstatniegoAdresata)
		return pobierzZPlikuIdOstatniegoAdresata();
	else
		return idOstatniegoAdresata;
}
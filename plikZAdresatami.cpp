#include "PlikZAdresatami.h"

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

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "plikZAdresatami.h"


int PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
	Adresat adresat;
	int idOstatniegoAdresata = 0;
	string daneJednegoAdresataOddzielonePionowymiKreskami = "";
	string daneOstaniegoAdresataWPliku = "";
	fstream plikTekstowy;
	plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);

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
	}
	else
		cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

	plikTekstowy.close();

	if (daneOstaniegoAdresataWPliku != "")
	{
		idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
		return idOstatniegoAdresata;
	}
	else
		return 0;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
	MetodyPomocnicze metodyPomocnicze;

	int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
	int idUzytkownika = metodyPomocnicze.konwersjaStringNaInt(metodyPomocnicze.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

	return idUzytkownika;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
	MetodyPomocnicze metodyPomocnicze;

	int pozycjaRozpoczeciaIdAdresata = 0;
	int idAdresata = metodyPomocnicze.konwersjaStringNaInt(metodyPomocnicze.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
	return idAdresata;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
	Adresat adresat;
	string pojedynczaDanaAdresata = "";
	int numerPojedynczejDanejAdresata = 1;

	int dlugoscDanychAdresataOddzielonePionowymiKreskami = daneAdresataOddzielonePionowymiKreskami.length();

	for (int pozycjaZnaku = 0; pozycjaZnaku < dlugoscDanychAdresataOddzielonePionowymiKreskami; pozycjaZnaku++)
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
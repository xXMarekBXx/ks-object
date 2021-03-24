#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "metodyPomocnicze.h"
#include "adresat.h"

using namespace std;

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
	ostringstream ss;
	ss << liczba;
	string str = ss.str();
	return str;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
	int liczbaInt;
	istringstream iss(liczba);
	iss >> liczbaInt;

	return liczbaInt;
}

string  MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
	if (!tekst.empty())
	{
		transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
		tekst[0] = toupper(tekst[0]);
	}
	return tekst;
}

string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
	string liczba = "";
	while (isdigit(tekst[pozycjaZnaku]) == 1)
	{
		liczba += tekst[pozycjaZnaku];
		pozycjaZnaku++;
	}
	return liczba;
}

bool MetodyPomocnicze::czyPlikJestPusty(fstream &plikTekstowy) {
	plikTekstowy.seekg(0, ios::end);
	if (plikTekstowy.tellg() == 0)
		return true;
	else
		return false;
}

string MetodyPomocnicze::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami() {
	
	Adresat adresat;

	string liniaZDanymiAdresata = "";

	liniaZDanymiAdresata += konwerjsaIntNaString(adresat.pobierzId()) + '|';
	liniaZDanymiAdresata += konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
	liniaZDanymiAdresata += adresat.pobierzImie() + '|';
	liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
	liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
	liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
	liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

	return liniaZDanymiAdresata;
}

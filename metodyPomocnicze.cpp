#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "metodyPomocnicze.h"

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
	while (isdigit(tekst[pozycjaZnaku]) == true)
	{
		liczba += tekst[pozycjaZnaku];
		pozycjaZnaku++;
	}
	return liczba;
}

#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <string>
#include <vector>
#include "uzytkownik.h"

using namespace std;

class MetodyPomocnicze {

public:

	static string konwerjsaIntNaString(int liczba);
	int konwersjaStringNaInt(string liczba);
	string  zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
	string pobierzLiczbe(string tekst, int pozycjaZnaku);
};

#endif
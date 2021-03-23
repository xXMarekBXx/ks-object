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
	static int konwersjaStringNaInt(string liczba);
	static string  zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
	static string pobierzLiczbe(string tekst, int pozycjaZnaku);
};

#endif
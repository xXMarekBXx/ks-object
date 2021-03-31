#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>

using namespace std;

class MetodyPomocnicze {
	
public:
	
	static string konwersjaIntNaString(int liczba);
	static int konwersjaStringNaInt(string liczba);
	static string wczytajLinie();
	static char wczytajZnak();
	static int wczytajLiczbeCalkowita();

};

#endif
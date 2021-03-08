#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "metodyPomocnicze.h"

using namespace std;

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
	ostringstream ss;
	ss << liczba;
	string str = ss.str();
	return str;
}


#include <iostream>
#include <string>
#include "uzytkownik.h"

using namespace std;

void Uzytkownik::ustawId(int noweId) {
	if(noweId>=0)
		id = noweId;
}
void Uzytkownik::ustawLogin(string nowyLogin) {
	login = nowyLogin;
}
void Uzytkownik::ustawHaslo(string noweHaslo) {
	haslo = noweHaslo;
}
int Uzytkownik::pobierzId() {
	return id;
}
string Uzytkownik::pobierzLogin() {
	return login;
}
string Uzytkownik::pobierzHaslo() {
	return haslo;
}
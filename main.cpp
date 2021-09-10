﻿#include <iostream>
#include "ksiazkaAdresowa.h"

using namespace std;

int main() {

	vector <Adresat> adresaci;
	KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
	
	while (true)
	{
		if (ksiazkaAdresowa.czyUzytkownikJestZalogowany() == false)
		{
		system("cls");
		cout << "    >>> MENU  GLOWNE <<<" << endl;
		cout << "-----------------------------" << endl;
		cout << "1. Rejestracja" << endl;
		cout << "2. Logowanie" << endl;
		cout << "9. zamknij program" << endl;
		cout << "Twoj wybor: ";
		int wybor;
		cin >> wybor;
				
			switch (wybor)
			{
			case 1:
				ksiazkaAdresowa.rejestracjaUzytkownika();
				break;
			case 2:
				ksiazkaAdresowa.logowanieUzytkownika();					
				break;
			case 9:
				exit(0);
				break;
			default:
				cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
				system("pause");
				break;
			}
		}else {	
			
			system("cls");
			cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
			cout << "---------------------------" << endl;
			cout << "1. Dodaj adresata" << endl;
			cout << "2. Wyszukaj po imieniu" << endl;
			cout << "3. Wyszukaj po nazwisku" << endl;
			cout << "4. Wyswietl adresatow" << endl;
			cout << "5. Usun adresata" << endl;
			cout << "6. Edytuj adresata" << endl;
			cout << "---------------------------" << endl;
			cout << "7. Zmien haslo" << endl;
			cout << "8. Wyloguj sie" << endl;
			cout << "---------------------------" << endl;
			cout << "Twoj wybor: ";
			int wybor;
			cin >> wybor;			

			switch (wybor)
			{
			case 1:
				 ksiazkaAdresowa.dodajAdresata();
				break;
			case 2:
				//ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
				break;
			case 3:
				//ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
				break;
			case 4:
				ksiazkaAdresowa.wyswietlWszystkichAdesatow();
				break;
			case 5:
				ksiazkaAdresowa.usunAdresata();
				break;
			case 6:
				ksiazkaAdresowa.edytujAdresata();
				break;
			case 7:
				ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
				break;
			case 8:				
				ksiazkaAdresowa.wylogowanieUzytkownika();
				break;
			}
		}
	}	
}

/*
#include "ksiazkaAdresowa.h"

int main() {		

	KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "adresaci-test.txt");
	ksiazkaAdresowa.logowanieUzytkownika();
	ksiazkaAdresowa.edytujAdresata();

}
*/

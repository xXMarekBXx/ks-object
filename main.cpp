#include <iostream>
#include <vector>
#include <string>
#include "uzytkownik.h"
#include "ksiazkaAdresowa.h"

int main() {
	KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
	ksiazkaAdresowa.wczytajUzytkownikowZPliku();
	//ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
	//ksiazkaAdresowa.rejestracjaUzytkownika();
	//ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

	int idZalogowanegoUzytkownika = 0;
			
	while (true)
	{
		cout << "MENU" << endl;
		cout << "-----------------------------" << endl;
		cout << "1. Rejestracja" << endl;
		cout << "2. Logowanie" << endl;
		cout << "9. zamknij program" << endl;
		int wybor;
		cin >> wybor;

		if (idZalogowanegoUzytkownika == 0)
		{
			switch (wybor)
			{
			case 1:
				ksiazkaAdresowa.rejestracjaUzytkownika();
				break;
			case 2:
				idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
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
			/*
			if (adresaci.empty() == true)
				// Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
				// Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
				// to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
				idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);
			*/
			cout << "7. Rejestracja" << endl;
			cout << "8. Logowanie" << endl;			
			int wybor;
			cin >> wybor;

			switch (wybor)
			{
			case 1:
				//idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
				break;
			case 2:
				//wyszukajAdresatowPoImieniu(adresaci);
				break;
			case 3:
				//wyszukajAdresatowPoNazwisku(adresaci);
				break;
			case 4:
				//wyswietlWszystkichAdresatow(adresaci);
				break;
			case 5:
				//idUsunietegoAdresata = usunAdresata(adresaci);
				//idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
				break;
			case 6:
				//edytujAdresata(adresaci);
				break;
			case 7:
				//zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
				break;
			case 8:
				idZalogowanegoUzytkownika = 0;				
				break;
			}
		}
	}	
}

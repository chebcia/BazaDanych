#pragma once
#include "ListaLekow.h"
#include "ZarzadzanieLekami.h"

class Magazyn {
	ZarzadzanieLekami zarzadzanieLekami = ZarzadzanieLekami();
public:
	Magazyn() {};
	Lek* znajdzlek(string nazwaleku, string nazwarodzaju);
	Listalekow* znajdzLeki();
	void dodajlek();
	void znajdzzamiennik(string choroba);
	template <typename T> void usunlek(string nazwaleku, string nazwarodzaju)
	{
		fstream plik;

		try
		{
			plik.open(nazwarodzaju + ".txt", std::ios::in);
			string linia;
			string nazwalekuzpliku;
			bool refundacja;
			double cena;
			int ograniczenia;
			int iloscsztuk;
			string numerserii;
			Listalekow* lista = NULL;

			while (getline(plik, linia)) {
				char * schowek;
				char* skonwertowany = new char[linia.length() + 1];
				strcpy(skonwertowany, linia.c_str());
				schowek = strtok(skonwertowany, " ");
				if (linia.compare("") != 0)
				{
					//while (schowek != NULL) {
					cout << schowek << endl;
					nazwalekuzpliku = schowek;
					if (nazwaleku != nazwalekuzpliku) {

						schowek = strtok(NULL, " ");
						refundacja = schowek;

						schowek = strtok(NULL, " ");
						cena = stoi(schowek);

						schowek = strtok(NULL, " ");
						ograniczenia = stoi(schowek);

						schowek = strtok(NULL, " ");
						iloscsztuk = stoi(schowek);

						schowek = strtok(NULL, " ");
						numerserii = schowek;

						Lek* lek = new Lek(nazwalekuzpliku, refundacja, cena, ograniczenia, numerserii, iloscsztuk);
						lista->dodajlekdolisty(lek, lista);

					}
				}

				delete skonwertowany;
			}
			plik.close();
			wypiszlistedopliku(nazwarodzaju, lista);
			usunlekzzamiennikow(nazwaleku);
		}
		catch (std::exception &e)
		{
			std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
			plik.close();
		}

	}
	void usunlekzzamiennikow(string nazwaleku);
	void zmniejszilosclekowojeden(string nazwaleku, string nazwarodzaju);
	void uzupelnijlek(string nazwaleku, string nazwarodzaju, int nowailosc);
	void wypiszlistedopliku(string nazwarodzaju, Listalekow* lista);
};
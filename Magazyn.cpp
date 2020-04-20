#include "Magazyn.h"

using namespace std;



Lek* Magazyn::znajdzlek(string nazwaleku, string nazwarodzaju) //parametr metody z klasy lek
{
	fstream plik;
	// sprawdzenie fragmentu instrukcj¹ try
	try
	{
		plik.open(nazwarodzaju + ".txt", std::ios::in);
		if (!plik.good())
		{
			throw std::exception("Nie istnieje taki rodzaj leku");
		}
		while (!plik.eof())
		{
			string napis;

			string nazwazpliku;
			bool refundacja;
			double cena;
			int ograniczenia;
			int iloscsztuk;
			string numerserii;
			getline(plik, napis, '\n');
			if (napis.compare("") != 0)
			{
				stringstream ss(napis);
				ss >> nazwazpliku >> refundacja >> cena >> ograniczenia >> iloscsztuk >> numerserii;
				if (nazwazpliku == nazwaleku)
				{
					return new Lek(nazwaleku, cena, refundacja, ograniczenia, numerserii, iloscsztuk);
					plik.close();
				}
			}
			else
			{
				plik.close();
			}
		}

		return nullptr;
	}
	// z³apanie wyj¹tku w przypadku niepowodzenia dostêpu do pliku
	catch (const std::exception &e )
	{
		std::cout <<std::endl << e.what() << std::endl;
		plik.close();
		return nullptr;
	}
}

Listalekow * Magazyn::znajdzLeki()
{
	return zarzadzanieLekami.znajdzLekarstwa();
}

void Magazyn::dodajlek()
{
	cout << "Wpisz rodzaj \n";
	string nazwaleku;
	string nazwarodzaju;

	cin >> nazwarodzaju;
	cout << "Wpisz nazwe leku\n";
	cin >> nazwaleku;

	Lek *lek = znajdzlek(nazwaleku, nazwarodzaju);

	if (lek != nullptr)
	{
		delete lek;
		cout << " Istnieje juz taki lek";

	}
	else
	{
		bool refundacja;
		string refundacjaString;
		double cena;
		int ograniczenia;
		int iloscsztuk;
		string numerserii;
		// sprawdznie fragmentu kodu podejrzanego o wyj¹tek 
		ofstream plik;
		// je¿eli otwarcie pliku by siê nie powiod³o rzucany jest wyj¹tek który ³apie instrukcja catch
		// je¿eli do jakiegoœ obiektu nie mo¿na by³o by siê odwo³aæ to rzucany jest wyj¹tek exception


		cout << "podaj cene : ";
		cin >> cena;
		cout << "podaj ograniczenia : ";
		cin >> ograniczenia;
		cout << "podaj ilosc sztuk : ";
		cin >> iloscsztuk;
		cout << "czy refundacja jest (tak/nie): ";
		getline(cin, refundacjaString);
		getline(cin, refundacjaString);//enter od razu wczytuje linie po cin i powoduje ze trzeba 2 razy sczytac
		cout << "podaj numer serii: ";
		getline(cin, numerserii);
		if (refundacjaString.compare("tak") == 0)
		{
			refundacja = true;
		}
		else
			if (refundacjaString.compare("nie") == 0)
			{
				refundacja = false;
			}

		try 
		{
			plik.open(nazwarodzaju + ".txt", ios::out | ios::app);
			plik << nazwaleku << " " << refundacja << " " << cena << " " << ograniczenia << " " << iloscsztuk << " " << numerserii << "\n";
			plik.close(); //obowi¹zkowo nale¿y zamkn¹æ plik
		}
		catch (const exception &e)
		{
			cout << "cos poszlo nie tak przy otwieraniu pliku!" << endl;
		}
		ofstream zamienniki;
		try {
			zamienniki.open("zamienniki.txt", ios::out | ios::app);
			string choroba;
			zamienniki << nazwaleku + " ";
			cout << "Wpisz choroby dla ktorych twoj lek jest zamiennikiem jezeli chcesz przestac wpisz 0";
			while (choroba != "0") {
				if (choroba == "0") {
					zamienniki << '\n';
				}
				cin >> choroba;
				zamienniki << choroba + " ";
			}
			zamienniki << "\n";

			zamienniki.close();
		}
		// z³panie wyj¹tku
		catch (const exception &e)
		{
			cout << "cos poszlo nie tak przy otwieraniu pliku!"<<" zamienniki.txt" << endl;
			zamienniki.close();
		}
	}
}

void Magazyn::znajdzzamiennik(string choroba)
{
	fstream plik;
	try {
		plik.open("zamienniki.txt", std::ios::in);

		while (!plik.eof())
		{
			string napis;
			string nazwazpliku;
			int iloscsztuk;
			getline(plik, napis, '\n');
			char * schowek;
			char* skonwertowany = new char[napis.length() + 1];
			strcpy(skonwertowany, napis.c_str());
			schowek = strtok(skonwertowany, " ");
			if (napis.compare("") != 0)
			{
			nazwazpliku = schowek;
				while (schowek != NULL) {
					if (schowek == choroba) {
						cout << "lekiem dzialajacym na te chorobe jest: " + nazwazpliku << endl;
					}
					schowek = strtok(NULL, " ");
				}
			}
		}
		plik.close();
	}
	catch (std::exception &e)
	{
		std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
		plik.close();
	}
}

void Magazyn::usunlekzzamiennikow(string nazwaleku)
{
	fstream plik;
	// sprawdzenie kodu podejrzanego o wyj¹tek
	try
	{
	plik.open("zamienniki.txt", std::ios::in);

		string linia;
		string nazwalekuzpliku;
		vector<string> liniezpliku;
		while (getline(plik, linia)) {
			char * schowek;
			char* skonwertowany = new char[linia.length() + 1];
			strcpy(skonwertowany, linia.c_str());
			schowek = strtok(skonwertowany, " ");

			if (linia.compare("") != 0)
			{
				nazwalekuzpliku = schowek;
				if (nazwaleku != nazwalekuzpliku) {
					liniezpliku.push_back(linia);


				}
			}
			delete skonwertowany;
		}
		plik.close();
		plik.open("zamienniki.txt", std::ofstream::out | std::ofstream::trunc);
		if (plik.good()) 
		{
			std::vector<string>::iterator cell = liniezpliku.begin();
			for (cell; cell!= liniezpliku.end(); cell++) {
				plik << *cell;
			}
		}
		plik.close();
	}
	// z³apanie wyj¹tku 
	catch (std::exception &e)
	{
		std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
		plik.close();
	}


}

void Magazyn::zmniejszilosclekowojeden(string nazwaleku, string nazwarodzaju)
{

	fstream plik;
	try
	{
	plik.open(nazwarodzaju + ".txt", std::ios::in);
		bool znaleziono = false;
		string linia;
		string nazwalekuzpliku;
		bool refundacja;
		double cena;
		int ograniczenia;
		string numerserii;
		int iloscsztuk;
		Listalekow* lista = NULL;

		while (getline(plik, linia)) {
			char * schowek;
			char* skonwertowany = new char[linia.length() + 1];
			strcpy(skonwertowany, linia.c_str());
			schowek = strtok(skonwertowany, " ");
			if (schowek != NULL) {
				nazwalekuzpliku = schowek;
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

				if (nazwaleku.compare( nazwalekuzpliku)==0) {
					znaleziono = true;
					if (iloscsztuk <= 0) {
						cout << "za malo leku: " + nazwaleku + " w bazie aby sprzedac, skontaktuj sie z managerem" << endl;
					}
					else {
						iloscsztuk--;
						cout << "sprzedano lek: " + nazwaleku + " pozostalo jeszcze: " + to_string(iloscsztuk) + " w bazie" << endl;
					}

				}
				Lek* lek = new Lek(nazwalekuzpliku, refundacja, cena, ograniczenia,numerserii, iloscsztuk);
				lista->dodajlekdolisty(lek, lista);


			}

			delete skonwertowany;
		}
		if (znaleziono == false) {
			cout << "Nie znaleziono podanego leku w bazie sprobuj ponownie dla innego rodzaju " << endl;
		}
		plik.close();
		wypiszlistedopliku(nazwarodzaju, lista);
	}
	catch (std::exception &e)
	{
		cout << "Dostep do bazy zabroniony" << endl;
		plik.close();
	}
	
}

void Magazyn::uzupelnijlek(string nazwaleku, string nazwarodzaju, int nowailosc)
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
			if (schowek != NULL) {
				nazwalekuzpliku = schowek;
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

				if (nazwaleku.compare(nazwalekuzpliku)==0) {
					iloscsztuk = nowailosc;
				}
				Lek* lek = new Lek(nazwalekuzpliku, refundacja, cena, ograniczenia, numerserii, iloscsztuk);
				lista->dodajlekdolisty(lek, lista);
			}

			delete skonwertowany;
		}
		plik.close();
		wypiszlistedopliku(nazwarodzaju, lista);
	}
	catch (exception & e)
	{
		plik.close();
		cout << "cos poszlo nie tak przy otwieraniu pliku!" << endl;
	}

}

void Magazyn::wypiszlistedopliku(string nazwarodzaju, Listalekow* lista) //metoda ktora sobie bierze listelekow a lista lekow to obiekt co nie?
{
	fstream plik;
	// sprawdŸ fragment kodu podejrzany o rzucenie wyj¹tku
	try
	{
		plik.open(nazwarodzaju + ".txt", std::ofstream::out | std::ofstream::trunc);
		Listalekow* przechowywatorglowy = lista;
		while (przechowywatorglowy)
		{
			plik << przechowywatorglowy->lek->getNazwaleku() << " " << przechowywatorglowy->lek->getRefundacja() <<
				" " << przechowywatorglowy->lek->getCena() << " " << przechowywatorglowy->lek->getOgraniczenia() << " " << przechowywatorglowy->lek->getIloscsztuk() <<" "<< przechowywatorglowy->lek->getNumerserii() << '\n';

			przechowywatorglowy = przechowywatorglowy->pNext;
		}

		Listalekow::wyczyscliste(lista);
		plik.close();
	}
	// z³apanie wyj¹tku
	catch (const exception &e)
	{
		cout << "Dostep do bazy zabroniony" << endl;
		plik.close();
	}
}


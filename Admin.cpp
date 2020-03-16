#include "Admin.h"

void Admin::dodajUzytkownika()
{

	cout << "Dodaj nowego uzytkownika, podaj login, haslo i role" << endl;
	string login;
	string haslo;
	string rola;
	cout << "Login: "<<endl;
	cin >> login;
	cout << "Haslo: "<<endl;
	cin >> haslo;
	cout << "rola: "<<endl;
	cin >> rola;

	ofstream plik( "hasla.txt", ios::out | ios::app);
	if (plik.good() == true)
	{
		plik << login << " " << haslo << " " << rola << '\n';
		plik.close(); //obowi¹zkowo nale¿y zamkn¹æ plik
		menu();
	}
	else {
		cout << "blad podczas dostepu do bazy uzytkownikow";
	}

}

void Admin::usunUzytkownika()
{
	cout << "Podaj login uzytkownika ktory ma zostac usuniety";
	string login;
	cout << "Login: ";
	cin >> login;

	fstream plik("hasla.txt", std::ios::in);

	if (plik.good() == true)
	{
		string linia;
		string loginzpliku;
		vector<string> liniezpliku;
		while (getline(plik, linia)) {
			char * schowek;
			char* skonwertowany = new char[linia.length() + 1];
			strcpy(skonwertowany, linia.c_str());
			schowek = strtok(skonwertowany, " ");

			cout << schowek << endl;
			loginzpliku = schowek;

			if (login != loginzpliku) {
				liniezpliku.push_back(linia+"\n");

			}
			delete skonwertowany;
		}
		plik.close();
		plik.open("hasla.txt", std::ofstream::out | std::ofstream::trunc);
		if (plik.good()) {
			for (int i = 0; i < liniezpliku.size(); i++) {
				plik << liniezpliku.at(i);
			}
		}
		plik.close();
	
	}
	else {
		cout << "blad podczas dostepu do bazy uzytkownikow";
	}


}

Admin::Admin()
{
	rola = "admin";
}

void Admin::menu()
{


	cout << "1.Dodaj uzytkownika" << endl;
	cout << "2.Usun uzytkownika" << endl;
	cout << "0.Wyjdz" << endl;

	int opcja;
	cin >> opcja;

	switch (opcja)
	{
	case 1:
		dodajUzytkownika();
		break;
	case 2:
		usunUzytkownika();
		break;
	case 0:
		exit(0);

	default:
		cout << "Bledna opcja";
		menu();
	}
}

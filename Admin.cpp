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

	int id=1;
	string linia;
	ifstream plik1("hasla.txt");
	
	if (plik1)
	{
		int aktualneID;
		while (getline(plik1, linia))
		{
			
			if (atoi(linia.c_str()) >id )
			{
				id = atoi(linia.c_str());
			}
		}
		plik1.close();
	}
	id++;
	ofstream plik( "hasla.txt", ios::out | ios::app);
	try
	{
		plik <<id <<" "<< login << " " << haslo << " " << rola << '\n';
		plik.close(); //obowi¹zkowo nale¿y zamkn¹æ plik
		menu();
	}
	catch (exception e)
	{
		cout << "Blad podczas dostepu do bazy uzytkownikow"<<endl;
		plik.close();
	}

}

void Admin::usunUzytkownika()
{
	cout << "Podaj login uzytkownika ktory ma zostac usuniety"<<endl;
	string login;
	cout << "Login: "<<endl;
	cin >> login;

	fstream plik("hasla.txt", std::ios::in);
	try
	{
		string linia;
		string loginzpliku;
		// u¿ycie vectora jako kontenera stl
		std::vector<string> liniezpliku;
		while (getline(plik, linia)) {
			char * schowek;
			char* skonwertowany = new char[linia.length() + 1];
			strcpy(skonwertowany, linia.c_str());
			schowek = strtok(skonwertowany, " ");

			//druga kolumna, login
			schowek = strtok(NULL, " ");

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
			// iterator stl 
			std::vector<string>::iterator cell = liniezpliku.begin();
			for (cell; cell!=liniezpliku.end(); cell++) {

				plik << *cell;
			}
		}
		plik.close();
	
	}
	catch(exception e)
	{
		cout << "Blad podczas dostepu do bazy uzytkownikow"<<endl;
		plik.close();
	}


}

Admin::Admin()
{
	rola = "admin";
}

void Admin::menu()
{
	int opcja = 1;
	while (opcja != 0)
	{

		cout << "1.Dodaj uzytkownika" << endl;
		cout << "2.Usun uzytkownika" << endl;
		cout << "0.Wyjdz" << endl;

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
			cout << "Bledna opcja" << endl;
		}
	}
}

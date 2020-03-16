#include "Logowanie.h"



string Logowanie::menulogowania()
{
	string login;
	string haslo;
	cout << "Zaloguj sie" << endl;
	cout << "Login: ";
	cin >> login;
	cout << "Haslo: ";
	cin >> haslo;
	return zalogujSie(login, haslo);
}


string Logowanie::zalogujSie(string login, string haslo)
{
	fstream plik;

	plik.open("hasla.txt", std::ios::in);
	if (plik.good() == true)
	{
		while (!plik.eof())
		{
			string linia;
			string rola;
			getline(plik, linia, '\n');

			char * schowek;
			char* skonwertowany = new char[linia.length() + 1];
			strcpy(skonwertowany, linia.c_str());
			if (strlen(skonwertowany) == 0) {
				break;
			}
			string loginzPliku = strtok(skonwertowany, " ");
			string haslozPliku = strtok(NULL, " ");
			if (login == loginzPliku && haslo == haslozPliku) {
				plik.close();
				return strtok(NULL, " ");

			}
			else if (login == loginzPliku && haslo != haslozPliku) {
				cout << "Podano bledne haslo aplikacja zostanie wylaczona!";
				Sleep(1000);
				plik.close();
				exit(0);
				return nullptr;

			}
		}

		cout << "Nie znaleziono uzytkownika o podanym hasle, aplikacja zostanie wylaczona!";
		Sleep(1000);
		plik.close();
		exit(0);
		//menulogowania();
		return nullptr;
	}
}

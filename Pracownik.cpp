#include "Pracownik.h"

Pracownik::Pracownik()
{
}

Pracownik::Pracownik(string login, string haslo, string rola)
{
	this->login = login;
	this->haslo = haslo;
	this->rola = rola;
}

//string Pracownik::zalogujSie(string login, string haslo){
//	fstream plik;
//
//	plik.open("hasla.txt", std::ios::in);
//	if (plik.good() == true)
//	{
//		while (!plik.eof())
//		{
//			string linia;
//			string rola;
//			getline(plik, linia, '\n');
//
//			char * schowek;
//			char* skonwertowany = new char[linia.length() + 1];
//			strcpy(skonwertowany, linia.c_str());
//			if (strlen(skonwertowany) == 0) {
//				break;
//			}
//			string loginzPliku = strtok(skonwertowany, " ");
//			string haslozPliku = strtok(NULL, " ");
//			if (login == loginzPliku && haslo == haslozPliku) {
//				plik.close();
//				return strtok(NULL, " ");
//
//			}
//			else if (login == loginzPliku && haslo != haslozPliku) {
//				cout << "Podano bledne haslo aplikacja zostanie wylaczona!";
//				Sleep(1000);
//				plik.close();
//				exit(0);
//				return nullptr;
//
//			}
//		}
//
//		cout << "Nie znaleziono uzytkownika o podanym hasle, aplikacja zostanie wylaczona!";
//		Sleep(1000);
//		plik.close();
//		exit(0);
//		//menulogowania();
//		return nullptr;
//	}
//}

//string Pracownik::menulogowania()
//{
//	string login;
//	string haslo;
//	cout << "Zaloguj sie" << endl;
//	cout << "Login: ";
//	cin >> login;
//	cout << "Haslo: ";
//	cin >> haslo;
//	Pracownik pracownik = Pracownik();
//	return zalogujSie(login, haslo);
//}

Lek Pracownik::podajNazweIRodzaj()
{
	string rodzajleku;
	cout << "podaj rodzaj leku: ";
	cin >> rodzajleku;
	string nazwaleku;
	cout << "podaj nazwe leku: ";
	cin >> nazwaleku;
	return Lek(nazwaleku, rodzajleku);
}


#include "Logowanie.h"

bool sprawdzDane(string login, string haslo)
{
	std::regex wyrazenieDuzaLitera{ "[A-Z]+" }; //znajdz du¿¹ litere
	std::regex wyrazenieMalaLitera{ "[a-z]+" }; //znadz ma³a liere
	std::regex wyrazenieCyfra{ "[0-9]+" }; //znajdz cyfre
	std::regex wyrazenieZnakSpecjalny{ "[@!?.]+" };// znadz znak
	bool duzaLitera = false; 
	bool malaLitera = false; 
	bool cyfra = false; 
	bool znakSpecjalny = false;
	duzaLitera = std::regex_search(login, wyrazenieDuzaLitera);
	malaLitera = std::regex_search(login, wyrazenieMalaLitera);
	cyfra = std::regex_search(login, wyrazenieCyfra);
	//sprawdz login
	if (uppercase&&malaLitera&&cyfra)
	{
		duzaLitera = std::regex_search(haslo, wyrazenieDuzaLitera);
		malaLitera = std::regex_search(haslo, wyrazenieMalaLitera);
		cyfra = std::regex_search(haslo, wyrazenieCyfra);
		znakSpecjalny = std::regex_search(haslo, wyrazenieZnakSpecjalny);
		if (duzaLitera&&malaLitera&&cyfra&&znakSpecjalny)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
}
string Logowanie::menulogowania()
{
	// regular expression szukanie wzorca w tekœcie w innym teksæie jeœli pasuje true jeœli nie false
	string login;
	string haslo;

	cout << "Zaloguj sie \n"
		<<"Login musi zawierac minimum 1 duza litere i cyfre \n" 
		<<"Haslo musi zawierac min. 1 duza litere, cyfre oraz znak specjalny @!?."
		<< endl;

	cout << "Login: ";
	cin >> login;
	cout << "Haslo: ";
	cin >> haslo;

	if (sprawdzDane(login,haslo))
	{
		return zalogujSie(login, haslo);
	}
	else 
	{
		cout << "login i haslo nie spelnia wymagan" << endl;
		return " ";
	}
	

}

string Logowanie::zalogujSie(string login, string haslo)
{
	fstream plik;
	try
	{
		plik.open("hasla.txt", std::ios::in);
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
			string id = strtok(skonwertowany, " ");
			string loginzPliku = strtok(NULL, " ");
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
	}
	// z³ap wyj¹tek je¿eli nie uda³o siê dostaæ do pliku
		catch (exception e)
		{
			cout << "Brak dostêpu do bazy";
		}
		cout << "Nie znaleziono uzytkownika o podanym hasle, aplikacja zostanie wylaczona!";
		Sleep(1000);
		plik.close();
		exit(0);
		//menulogowania();
		return nullptr;
}

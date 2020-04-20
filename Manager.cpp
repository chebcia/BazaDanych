#include "Manager.h"

Manager::Manager()
{
	rola = "manager";
}

void Manager::menu()
{
	int opcja=1;
	while (opcja != 0)
	{
		cout << "1.Dodaj lek" << endl;
		cout << "2.Usun lek" << endl;
		cout << "3.Uzupe³nij lek" << endl;
		cout << "4.Sprzedaj lek" << endl;
		cout << "5.Znajdz zamiennik" << endl;
		cout << "6.Znajdz lek" << endl;
		cout << "7.Znajdz lekarstwa" << endl;
		cout << "0.Wyjdz" << endl;


		cin >> opcja;

		switch (opcja)
		{
		case 1:
			dodajLek();
			break;
		case 2:
			usunLek();
			break;
		case 3:
			uzupelnijLek();
			break;
		case 4:
			sprzedajLek();
			break;
		case 5:
			znajdzZamiennik();
			break;
		case 6:
			znajdzlek();
			break;
		case 7:
			znajdzlekarstwa();
			break;
		case 0:
			exit(0);
		default:
			cout << "Bledna opcja";
		}
	}

}

void Manager::dodajLek()
{
	Lek lek = Lek();
	Magazyn magazyn = Magazyn();
	magazyn.dodajlek();
}

void Manager::usunLek()
{
	Lek lek = podajNazweIRodzaj();
	Magazyn magazyn = Magazyn();
	magazyn.usunlek<string>(lek.getNazwaleku(), lek.getRodzajleku());
}

void Manager::uzupelnijLek()
{
	Lek lek = podajNazweIRodzaj();
	Magazyn magazyn = Magazyn();
	cout << "Podaj nowa ilosc leku" << endl;
	int nowailosc;
	cin >> nowailosc;
	magazyn.uzupelnijlek(lek.getNazwaleku(), lek.getRodzajleku(), nowailosc);
}

#include "Manager.h"

Manager::Manager()
{
	rola = "manager";
}

void Manager::menu()
{

	cout << "1.Dodaj lek" << endl;
	cout << "2.Usun lek" << endl;
	cout << "3.Uzupe³nij lek" << endl;
	cout << "4.Sprzedaj lek" << endl;
	cout << "5.Znajdz zamiennik" << endl;
	cout << "6.Znajdz lek" << endl;
	cout << "0.Wyjdz" << endl;

	int opcja;
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
		menu();
		break;
	case 5:
		znajdzZamiennik();
		menu();
		break;
	case 6:
		znajdzlek();
		menu();
		break;
	case 0:
		exit(0);
	default:
		cout << "Bledna opcja";
		menu();
	}

}

void Manager::dodajLek()
{
	Lek lek = Lek();
	Magazyn magazyn = Magazyn();
	magazyn.dodajlek();
	menu();
}

void Manager::usunLek()
{
	Lek lek = podajNazweIRodzaj();
	Magazyn magazyn = Magazyn();
	magazyn.usunlek<string>(lek.getNazwaleku(), lek.getRodzajleku());
	menu();
}

void Manager::uzupelnijLek()
{
	Lek lek = podajNazweIRodzaj();
	Magazyn magazyn = Magazyn();
	cout << "Podaj nowa ilosc leku" << endl;
	int nowailosc;
	cin >> nowailosc;
	magazyn.uzupelnijlek(lek.getNazwaleku(), lek.getRodzajleku(), nowailosc);
	menu();
}

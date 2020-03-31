#include "Sprzedawca.h"

Sprzedawca::Sprzedawca()
{
	this->rola = "sprzedawca";
}

void Sprzedawca::znajdzlek()
{
	Lek lek = podajNazweIRodzaj();
	Magazyn magazyn = Magazyn();
	Lek * znalezionylek = magazyn.znajdzlek(lek.getNazwaleku(), lek.getRodzajleku());
	if (znalezionylek != nullptr)
	{
		cout << "Ograniczenia znalezionego leku to: " << znalezionylek->getOgraniczenia() << "lat" << endl;
		cout << "Cena znalezionego leku to: " << znalezionylek->getCena() << "PLN"  << endl;
		cout << "Refundacja znalezionego leku to: " << znalezionylek->getRefundacja() << "PLN" << endl;
		cout << "Ilosc sztuk znalezionego leku to: " << znalezionylek->getIloscsztuk() << endl;
		cout << "Numer serii znalezionego leku to: " << znalezionylek->getNumerserii() << endl;
	
	}
	delete znalezionylek;
	if (rola == "sprzedawca")
		menu();
}

void Sprzedawca::menu()
{


	cout << "1.Sprzedaj lek" << endl;
	cout << "2.Znajdz zamiennik" << endl;
	cout << "3.Znajdz lek" << endl;
	cout << "0.Wyjdz" << endl;

	int opcja;
	cin >> opcja;

	switch (opcja)
	{
	case 1:
		sprzedajLek();
		break;
	case 2:
		znajdzZamiennik();
		break;
	case 3:
		znajdzlek();
		break;
	case 0:
		exit(0);
		break;
	default:
		cout << "Bledna opcja";
		menu();
	}
}

void Sprzedawca::sprzedajLek()
{
	Lek lek = podajNazweIRodzaj();
	Magazyn magazyn = Magazyn();

	magazyn.zmniejszilosclekowojeden(lek.getNazwaleku(), lek.getRodzajleku());
	if(rola=="sprzedawca")
		menu();

}

void Sprzedawca::znajdzZamiennik()
{
	Lek lek = Lek();
	Magazyn magazyn = Magazyn();
	string choroba;
	cout << "Podaj chorobe dla ktorej szukasz lekow " << endl;
	cin >> choroba;
	magazyn.znajdzzamiennik(choroba);
	if (rola == "sprzedawca")
		menu();
}

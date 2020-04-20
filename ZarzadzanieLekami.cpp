#include "ZarzadzanieLekami.h"

#include <thread>
#include <string>
#include <iostream>


void szukajPoKategorii(Lek lekarstwo, string nazwarodzaju, Listalekow*& listalekow,bool czySzukacPoRefundacji)
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
			string rodzajLeku;
			getline(plik, napis, '\n');
			stringstream ss(napis);
			if (napis.compare("") != 0)
			{
				ss >> nazwazpliku >> refundacja >> cena >> ograniczenia >> iloscsztuk >> numerserii;
				bool czyToLekSzukany = true;
				if (lekarstwo.getCena() != -1 && lekarstwo.getCena() != cena)
				{
					czyToLekSzukany = false;
				}
				else
					if (lekarstwo.getIloscsztuk() != -1 && lekarstwo.getIloscsztuk() != iloscsztuk)
					{
						czyToLekSzukany = false;
					}
					else
						if (czySzukacPoRefundacji && lekarstwo.getRefundacja() != refundacja)
						{
							czyToLekSzukany = false;
						}
						else
							if (lekarstwo.getNazwaleku().compare("") != 0 && lekarstwo.getNazwaleku().compare(nazwazpliku) != 0)
							{
								czyToLekSzukany = false;
							}
							else
								if (lekarstwo.getOgraniczenia() != -1 && lekarstwo.getOgraniczenia() != ograniczenia)
								{
									czyToLekSzukany = false;
								}
								else
									if (lekarstwo.getNumerserii().compare("") != 0 && lekarstwo.getNumerserii().compare(numerserii) != 0)
									{
										czyToLekSzukany = false;
									}


				if (czyToLekSzukany)
				{
					Lek* lek = new Lek(nazwazpliku, refundacja, cena, ograniczenia, numerserii, iloscsztuk);
					listalekow->dodajlekdolisty(lek, listalekow);
				}
			}

		}
	}
	// z³apanie wyj¹tku w przypadku niepowodzenia dostêpu do pliku
	catch (const std::exception &e)
	{
		std::cout << std::endl << e.what() << std::endl;
		plik.close();
	}
}




Listalekow * ZarzadzanieLekami::znajdzLekarstwa(Lek lekarstwo,bool czySzukacPoRefundacji)
{
	string nazwaKategorii;
	cout << "podaj kategorie leku (nic by nie korzystac z pola): ";
	getline(cin, nazwaKategorii);
	vector<string> listaKategorii;
	Listalekow* listaZnalezionychLekow = NULL;

	if (nazwaKategorii.compare("") != 0)
	{
		listaKategorii.push_back(nazwaKategorii);
	}
	else

	{
		fstream plik;
		// sprawdzenie fragmentu instrukcj¹ try
		try
		{
			plik.open("Kategorie.txt", std::ios::in);
			if (!plik.good())
			{
				throw std::exception("Nie ");
			}
			while (!plik.eof())
			{
				string napis;


				getline(plik, napis);
				listaKategorii.push_back(napis);

			}
		}
		catch (const std::exception &e)
		{
			std::cout << std::endl << e.what() << std::endl;
			plik.close();
		}
	}



	std::vector<std::thread> watki(listaKategorii.size());
	for (int a = 0; a < listaKategorii.size(); a++)
	{
		string tmp = listaKategorii[a];
		watki[a] = std::thread(szukajPoKategorii, lekarstwo, tmp, std::ref(listaZnalezionychLekow),czySzukacPoRefundacji);
	}
	for (int a = 0; a < listaKategorii.size(); ++a)
	{
		watki[a].join();
	}
	return listaZnalezionychLekow;
}

Listalekow * ZarzadzanieLekami::znajdzLekarstwa()
{
	string nazwaleku;
	string refundacjaString;
	double cena;
	int ograniczenia;
	int iloscsztuk;
	string numerserii;
	string rodzajLeku;
	cout << "podaj nazwe leku (nic by nie korzystac z pola): ";
	getline(cin, nazwaleku);
	getline(cin, nazwaleku);
	cout << "podaj cene (-1 by nie korzystac z pola): ";
	cin >> cena;
	cout << "podaj ograniczenia (-1 by nie korzystac z pola): ";
	cin >> ograniczenia;
	cout << "podaj ilosc sztuk (-1 by nie korzystac z pola): ";
	cin >> iloscsztuk;
	cout << "czy refundacja jest (nic/tak/nie): ";
	getline(cin, refundacjaString);
	getline(cin, refundacjaString);//enter od razu wczytuje linie po cin i powoduje ze trzeba 2 razy sczytac
	cout << "podaj numer serii (nic by nie korzystac z pola): ";
	getline(cin, (numerserii));
	if (refundacjaString.compare("tak") == 0)
	{
		return ZarzadzanieLekami::znajdzLekarstwa(Lek(nazwaleku, true, cena, ograniczenia, numerserii, iloscsztuk),true);
	}
	else
		if (refundacjaString.compare("nie") == 0)
		{
			return ZarzadzanieLekami::znajdzLekarstwa(Lek(nazwaleku, false, cena, ograniczenia, numerserii, iloscsztuk),true);
		}
		else
		{
			return ZarzadzanieLekami::znajdzLekarstwa(Lek(nazwaleku,false, cena, ograniczenia, numerserii, iloscsztuk),false);
		}


}



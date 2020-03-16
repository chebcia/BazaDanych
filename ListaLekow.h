#pragma once
#include "lek.h"
class Listalekow
{

private: 
	int rozmiar = 0;
public:
	Listalekow  * pNext;
	Lek* lek;

	static void dodajlekdolisty(Lek* lek, Listalekow  *&pHead);

	Listalekow(Listalekow * listalekow, Lek* lek);
	Listalekow();
	~Listalekow();
	static void usunlekponazwie(string nazwaleku, Listalekow  *&pHead);
	static void wyczyscliste(Listalekow *& pHead);
	static Lek znajdzLekPoNazwie(Listalekow *& pHead, string nazwaleku);

	int getRozmiar() {
		return this->rozmiar;
	}
};
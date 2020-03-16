#pragma once
#include "ListaLekow.h"

class Magazyn {

public:
	Magazyn() {};
	Lek* znajdzlek(string nazwaleku, string nazwarodzaju);
	void dodajlek();
	void znajdzzamiennik(string choroba);
	void usunlek(string nazwaleku, string nazwarodzaju);
	void usunlekzzamiennikow(string nazwaleku);
	void zmniejszilosclekowojeden(string nazwaleku, string nazwarodzaju);
	void uzupelnijlek(string nazwaleku, string nazwarodzaju, int nowailosc);
	void wypiszlistedopliku(string nazwarodzaju, Listalekow* lista);
};
#pragma once
#include "Sprzedawca.h"
class Manager : public Sprzedawca {


public:
	Manager();
	void menu();
	void dodajLek();
	void usunLek();
	void uzupelnijLek();

};
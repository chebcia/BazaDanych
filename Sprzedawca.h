#pragma once
#include "Pracownik.h"
class Sprzedawca : public Pracownik {

public:
	Sprzedawca();
	void menu();
protected:
	void sprzedajLek();
	void znajdzZamiennik();
	void znajdzlek();

};
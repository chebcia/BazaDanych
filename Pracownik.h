#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include "Magazyn.h"
#include <stdlib.h>

using namespace std;
class Pracownik {

public: 
	Pracownik();
	Pracownik(string login, string haslo, string rola);

	Lek podajNazweIRodzaj();
protected:
	string login;
	string haslo;
	string rola;
	int nrID;


};
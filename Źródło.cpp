#include <iostream>
#include <string>
#include "Logowanie.h"
#include "Admin.h"
#include "Manager.h"
using namespace std;



int main()
{
	Logowanie logowanie = Logowanie();
	//Pracownik pracownik = Pracownik();
	string rola = logowanie.menulogowania();
	if (rola == "admin") {
		Admin admin = Admin();
		admin.menu();
	}
	else if (rola == "sprzedawca") {
		Sprzedawca sprzedawca = Sprzedawca();
		sprzedawca.menu();
	}
	else if (rola == "manager") {
		Manager manager = Manager();
		manager.menu();
	}
	else {
		logowanie.menulogowania();
	}

	return 0;
}

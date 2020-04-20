#include <iostream>
#include <string>
#include "Logowanie.h"
#include "Admin.h"
#include "Manager.h"
#include "ZarzadzanieLekami.h"
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
		main();
	}

	return 0;
}

//No i teraz tak dosta�am komentarz
//niech Pani stworzy osobne  klasy do wyszukiwania dodawania usuwania lek�w  po obiekcie stanowisko(rola  jako)   aby by�a mo�liwo�� wyszukania lek�w po dowolnym parametrze na temat lek�w.
//ka�dy element w systemie powinien mie� swoje id bo co gdy jest dw�ch Adam�w Nowak�w.musi  pani zaimplementowa� sama dynamiczn�  struktur� danych
//niech pani wprowadzi osobne id  dla u�ytkownik�w oraz specjaln� klas� do wyszukiwania   po wszystkich parametrach leku.

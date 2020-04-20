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

//No i teraz tak dosta³am komentarz
//niech Pani stworzy osobne  klasy do wyszukiwania dodawania usuwania leków  po obiekcie stanowisko(rola  jako)   aby by³a mo¿liwoœæ wyszukania leków po dowolnym parametrze na temat leków.
//ka¿dy element w systemie powinien mieæ swoje id bo co gdy jest dwóch Adamów Nowaków.musi  pani zaimplementowaæ sama dynamiczn¹  strukturê danych
//niech pani wprowadzi osobne id  dla u¿ytkowników oraz specjaln¹ klasê do wyszukiwania   po wszystkich parametrach leku.

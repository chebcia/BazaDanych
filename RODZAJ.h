#pragma once
#include <string>
#include <vector>
#include <iostream>



using namespace std;


class Rodzaj
{

	string rodzajleku;
	string sciezkadopliku;
//	vector<Lek> leki; //lista lekow

public:
	const string &getRodzajleku() const {
		return rodzajleku;
	}

	void setRodzajleku(const string &rodzajleku) {
		Rodzaj::rodzajleku = rodzajleku;
	}

	const string &getSciezkadopliku() const {
		return sciezkadopliku;
	}

	void setSciezkadopliku(const string &sciezkadopliku) {
		Rodzaj::sciezkadopliku = sciezkadopliku;
	}

	/*const vector <Lek> &getLeki() const {
		return leki;
	}

	void setLeki(const vector <Lek> &leki) {
		Rodzaj::leki = leki;
	}*/

	Rodzaj(const string &rodzajleku, const string &sciezkadopliku /*const vector <Lek> &leki*/) : rodzajleku(rodzajleku), sciezkadopliku(sciezkadopliku) /*leki(leki)*/
	{

	}
	virtual ~Rodzaj() {

	}
	Rodzaj() {

	}
	void wyswietlanielistylekow();





};




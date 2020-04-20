#pragma once
#include <vector>
#include <string>
#include "RODZAJ.h"
#include <fstream>
#include <sstream> 
#include"Windows.h"
using namespace std;

class Lek
{  

private:
	string nazwaleku;
	string rodzajleku; 
	string numerserii;
	bool refundacja; 
	double cena;
	int ograniczenia;
	int iloscsztuk;

public:

	Lek(string nazwaleku,string rodzajleku, bool refundacja, double cena, int ograniczenia,string numerserii, int iloscsztuk);
	Lek(string nazwaleku, bool refundacja, double cena, int ograniczenia, string numerserii,  int iloscsztuk);
	Lek(string nazwaleku, string rodzajleku);

    ~Lek();
	
	Lek() {};
	
	const string &getNazwaleku() const {
		return nazwaleku;
	}
	
	bool operator ==(const Lek & v)
	{
		if ((this->nazwaleku == v.nazwaleku))
			return true;
		else
			return false;

	}

	void setNazwaleku(const string &nazwaleku) {
		Lek::nazwaleku = nazwaleku;
	}
	
	const string &getRodzajleku() const {
		return rodzajleku;
	}

	void setRodzajleku(const string &rodzajleku) {
		Lek::rodzajleku = rodzajleku;
	}

	bool isRefundacja() const {
		return refundacja;
	}

	void setRefundacja(bool refundacja) {
		Lek::refundacja = refundacja;
	}

	double getCena() const {
		return cena;
	}

	void setCena(double cena) {
		Lek::cena = cena;
	}

	int getOgraniczenia() const {
		return ograniczenia;
	}

	void setOgraniczenia(int ograniczenia) {
		Lek::ograniczenia = ograniczenia;
	}

	const string &getNumerserii() const {
		return numerserii;
	}

	void setChoroby(const string &numerserii) {
		Lek::numerserii = numerserii;
	}

	int getIloscsztuk() const {
		return iloscsztuk;
	}

	void setIloscsztuk(int iloscsztuk) {
		Lek::iloscsztuk = iloscsztuk;
	}
	bool getRefundacja() const {
		return refundacja;
	}
	string getRodzajLeku() const
	{
		return rodzajleku;
	}
	
};

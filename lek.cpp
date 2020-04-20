#include <iostream>
#include "lek.h"





Lek::Lek(string nazwaleku, string rodzajleku, bool refundacja, double cena, int ograniczenia, string numerserii, int iloscsztuk)
{
	this->nazwaleku = nazwaleku;
	this->rodzajleku = rodzajleku;
	this->cena = cena;
	this->numerserii = numerserii;
	this->iloscsztuk = iloscsztuk;
	this->ograniczenia = ograniczenia;
	this->refundacja = refundacja;

}
Lek::Lek(string nazwaleku, bool refundacja, double cena, int ograniczenia, string numerserii, int iloscsztuk)
{
	this->nazwaleku = nazwaleku;
	this->cena = cena;
	this->iloscsztuk = iloscsztuk;
	this->ograniczenia = ograniczenia;
	this->numerserii = numerserii;
	this->refundacja = refundacja;

}

Lek::Lek(string nazwaleku, string rodzajleku)
{
	this->nazwaleku = nazwaleku;
	this->rodzajleku = rodzajleku;
}

Lek::~Lek()
{

}






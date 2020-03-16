#pragma once
#include"Windows.h"
#include <string>
#include <fstream>
#include <sstream> 
#include <iostream>
using namespace std;
class Logowanie {


public:
	Logowanie() { }
	string menulogowania();
	string zalogujSie(string login, string haslo);
};
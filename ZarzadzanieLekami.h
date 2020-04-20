#pragma once
#include "ListaLekow.h"
#include <string>
#include <iostream>
class ZarzadzanieLekami {

public:
	Listalekow* znajdzLekarstwa(Lek lekarstwo, bool czySzukacPoRefundacji);
	Listalekow* znajdzLekarstwa();


};
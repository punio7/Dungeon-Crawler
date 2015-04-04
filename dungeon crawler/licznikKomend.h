#pragma once

#define ILOSC_KOMEND 100

#include <iostream>
#include "command_tree.h"

;using namespace std;

class licznikKomend
{
public:
	licznikKomend();
	
	void zwieksz(Ekomenda komenda);
	int sprawdz(Ekomenda komenda);
	void wypiszLicznik();			//wypisuje na wcout ilosc wywolan wszystkich funkcji

private:
	int iloscWywolan[ILOSC_KOMEND];
};
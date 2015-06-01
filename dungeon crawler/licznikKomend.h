#pragma once
#include "EnumKomendy.h"

class licznikKomend
{
public:
	licznikKomend();
	
	void zwieksz(Ekomenda komenda);
	int sprawdz(Ekomenda komenda);
	void wypiszLicznik();			//wypisuje na wcout ilosc wywolan wszystkich funkcji

private:
	int iloscWywolan[LICZBA_KOMEND];
};
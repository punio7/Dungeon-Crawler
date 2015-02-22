#include "Rozmowa.h"
#include "Kwestia.h"
#include "wersalikuj.h"


Rozmowa::Rozmowa(void)
{
	obecnaKwestia=domyslnaKwestia=1;
	kwestie.clear();
}


Rozmowa::~Rozmowa(void)
{
	for (Kwestia* aktualna : kwestie)
	{
		delete aktualna;
	}
}

Kwestia* Rozmowa::znajdzObecnaKwestia()
{
	return znajdzKwestie(obecnaKwestia);
}

Kwestia* Rozmowa::znajdzKwestie(int numer)
{
	for (Kwestia* aktualna : kwestie)
	{
		if (aktualna->numer == numer)
		{
			return aktualna;
		}
	}
	return NULL;
}

Kwestia* Rozmowa::dodajKwestie(Kwestia* kwestia)
{
	kwestie.push_back(kwestia);
	return kwestia;
}
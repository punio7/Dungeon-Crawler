#include "MiksturaZdarzeniaGlobalnego.h"
#include "Postac.h"
#include "Status.h"
#include "Color.h"
#include "playerMsg.h"
#include "zdarzeniaGlobalne.h"

MiksturaZdarzeniaGlobalnego::MiksturaZdarzeniaGlobalnego(int id, ItemTyp itemTyp, wstring nazwa, wstring opis, wstring iddle, int wartosc, int zdarzenieGlobalne)
{
	this->id = id;
	this->typ = itemTyp;
	this->nazwa = nazwa;
	this->opis = opis;
	this->idle = iddle;
	this->wartosc = wartosc;
	this->zdarzenieGlobalne = zdarzenieGlobalne;
}

bool MiksturaZdarzeniaGlobalnego::drink(Postac* postac)
{
	wywolajZdarzenieGlobalne(zdarzenieGlobalne);
	
	return true;
}
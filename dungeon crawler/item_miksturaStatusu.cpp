#include "item_miksturaStatusu.h"
#include "postac.h"
#include "status.h"
#include "color.h"

miksturaStatusu::miksturaStatusu(int id, wstring nazwa, wstring opis, wstring iddle, int wartosc, Status *status)
{
	this->id = id;
	this->typ = ITEM_MIKSTURA;
	this->nazwa = nazwa;
	this->opis = opis;
	this->idle = iddle;
	this->wartosc = wartosc;
	this->status = status;
}

bool miksturaStatusu::drink(Postac *postac)
{
	postac->statusy->dodaj(status);
	color(CYAN);
	wcout<<status->enterMsg<<endl;
	color(HWHITE);
	return true;
}
#include "item_miksturaStatusu.h"
#include "postac.h"
#include "status.h"
#include "color.h"

miksturaStatusu::miksturaStatusu(int id, string nazwa, string opis, string iddle, int wartosc, Status *status)
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
	cout<<status->enterMsg<<endl;
	color(HWHITE);
	return true;
}
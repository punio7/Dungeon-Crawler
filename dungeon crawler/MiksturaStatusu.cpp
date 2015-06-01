#include "MiksturaStatusu.h"
#include "Postac.h"
#include "Status.h"
#include "Color.h"
#include "playerMsg.h"

MiksturaStatusu::MiksturaStatusu(int id, wstring nazwa, wstring opis, wstring iddle, int wartosc, Status *status)
{
	this->id = id;
	this->typ = ITEM_MIKSTURA;
	this->nazwa = nazwa;
	this->opis = opis;
	this->idle = iddle;
	this->wartosc = wartosc;
	this->status = status;
}

bool MiksturaStatusu::drink(Postac *postac)
{
	postac->statusy->dodaj(status);
	playerMsg(L"|c|0", status->enterMsg);
	return true;
}
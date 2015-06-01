#pragma once
#include "Item.h"

class Postac;
class Status;

class MiksturaZdarzeniaGlobalnego: public Item
{
public:
	MiksturaZdarzeniaGlobalnego(int id, ItemTyp itemTyp, std::wstring nazwa, std::wstring opis, std::wstring iddle, int wartosc, int zdarzenieGlobalne);

	bool drink(Postac *postac);

	int zdarzenieGlobalne;
};
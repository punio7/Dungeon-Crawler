#pragma once
#include "komenda.h"

class Item;

class Put :
	public Komenda
{
public:
	Put(Gra *gra);
	~Put(void);

	void execute(ParseDTO argumenty);
	void manual();

	void putAll(Item *pojemnik);
	void put(Item *przedmiot, Item* pojemnik);
};


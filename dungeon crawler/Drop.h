#pragma once
#include "komenda.h"

class Item;

class Drop :
	public Komenda
{
public:
	Drop(Gra *gra);
	~Drop(void);

	void execute(ParseDTO argumenty);
	void manual();
	void drop(Item *przedmiot);
};


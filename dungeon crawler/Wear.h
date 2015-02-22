#pragma once
#include "komenda.h"

class Item;

class Wear :
	public Komenda
{
public:
	Wear(Gra *gra);
	~Wear(void);

	void execute(ParseDTO argumenty);
	void manual();
	void sprawdzWymagania(Item *item);
};


#pragma once
#include "komenda.h"

enum ItemSlot;

class Remove :
	public Komenda
{
public:
	Remove(Gra *gra);
	~Remove(void);

	void execute(ParseDTO argumenty);
	void manual();
	//zdejmuje przedmiot i wyswietla komunikaty, nie przelicza postaci
	void remove(ItemSlot slot);
};


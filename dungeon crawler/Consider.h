#pragma once
#include "komenda.h"

class Item;
class Postac;

class Consider :
	public Komenda
{
public:
	Consider(Gra *gra);
	~Consider(void);

	void execute(ParseDTO argumenty);
	void manual();
	void consider(Item *porownywany);
	void consider(Postac *przeciwnik);
};


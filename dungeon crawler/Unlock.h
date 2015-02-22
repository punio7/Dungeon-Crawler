#pragma once
#include "komenda.h"

class Item;

class Unlock :
	public Komenda
{
public:
	Unlock(Gra *gra);
	~Unlock(void);

	void execute(ParseDTO argumenty);
	void manual();

	void unlockDoor(KierunekSwiata kierunek);
	void unlockChest(Item *cel);
};


#pragma once

#include "Item.h"

;using namespace std;

class ItemZbroja: public Item
{
public:
	ItemZbroja();
	~ItemZbroja();

	void ustaw_staty(int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw);
	void ustaw_wymagania(int sila, int zre, int zwi, int wyt, int zyw);
	Staty czytaj_staty();
	ItemSlot getSlot();

	int atak, obrona, dmg, ochrona, pancerz, hp, cw;
	int wymSila, wymZre, wymZwin, wymWyt, wymZyw;
};
#include "item_1hbron.h"

item_1hbron::item_1hbron()
{
	Item::Item();
	typ=ITEM_1HWEAPON;

	atak=0, obrona=0, dmg=0, ochrona=0, pancerz=0, hp=0, cw=0;
	wymSila=0, wymZre=0, wymZwin=0, wymWyt=0, wymZyw=0;
}

item_1hbron::~item_1hbron()
{

}

void item_1hbron::ustaw_staty(int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw)
{
	this->atak=atak;
	this->obrona=obrona;
	this->dmg=dmg;
	this->ochrona=ochrona;
	this->pancerz=pancerz;
	this->hp=hp;
	this->cw=cw;
}

void item_1hbron::ustaw_wymagania(int sila, int zre, int zwi, int wyt, int zyw)
{
	wymSila=sila;
	wymZre=zre;
	wymZwin=zwi;
	wymWyt=wyt;
	wymZyw=zyw;
}

Staty item_1hbron::czytaj_staty()
{
	Staty *staty=new Staty;

	staty->atak=atak;
	staty->obrona=obrona;
	staty->dmg=dmg;
	staty->ochrona=ochrona;
	staty->pancerz=pancerz;
	staty->hp=hp;
	staty->cw=cw;

	staty->sil=wymSila;
	staty->zr=wymZre;
	staty->zw=wymZwin;
	staty->wyt=wymWyt;
	staty->zyw=wymZyw;

	return *staty;
}

ItemSlot item_1hbron::getSlot()
{
	switch (typ)
	{
	case ITEM_1HWEAPON:
		return SLOT_PREKA;
		break;
	case ITEM_2HWEAPON:
		return SLOT_PREKA;
		break;
	case ITEM_TARCZA:
		return SLOT_LREKA;
		break;
	case ITEM_WILD_1HWEAPON:
		return SLOT_PREKA;
		break;
	case ITEM_WILD_2HWEAPON:
		return SLOT_PREKA;
		break;
	case ITEM_WILD_TARCZA:
		return SLOT_LREKA;
		break;

	default:
		return (ItemSlot)-1;
		break;
	}
}
#include "item_zbroja.h"

item_zbroja::item_zbroja()
{
	Item::Item();
	typ=ITEM_ZBROJA;

	atak=0, obrona=0, dmg=0, ochrona=0, pancerz=0, hp=0, cw=0;
	wymSila=0, wymZre=0, wymZwin=0, wymWyt=0, wymZyw=0;
}

item_zbroja::~item_zbroja()
{

}

void item_zbroja::ustaw_staty(int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw)
{
	this->atak=atak;
	this->obrona=obrona;
	this->dmg=dmg;
	this->ochrona=ochrona;
	this->pancerz=pancerz;
	this->hp=hp;
	this->cw=cw;
}

void item_zbroja::ustaw_wymagania(int sila, int zre, int zwi, int wyt, int zyw)
{
	wymSila=sila;
	wymZre=zre;
	wymZwin=zwi;
	wymWyt=wyt;
	wymZyw=zyw;
}

Staty item_zbroja::czytaj_staty()
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

ItemSlot item_zbroja::getSlot()
{
	switch (typ)
	{
	case ITEM_ZBROJA:
		return SLOT_ZBROJA;
		break;
	case ITEM_NARAMIENNIKI:
		return SLOT_NARAMIENNIKI;
		break;
	case ITEM_REKAWICE:
		return SLOT_REKAWICE;
		break;
	case ITEM_NAGOLENNIKI:
		return SLOT_NAGOLENNIKI;
		break;
	case ITEM_BUTY:
		return SLOT_BUTY;
		break;
	case ITEM_HELM:
		return SLOT_BUTY;
		break;

	case ITEM_KOSZULA:
		return SLOT_KOSZULA;
		break;
	case ITEM_SPODNIE:
		return SLOT_SPODNIE;
		break;
	case ITEM_PIERSCIEN:
		return SLOT_PIERSCIENR;
		break;
	case ITEM_NASZYJNIK:
		return SLOT_NASZYJNIK;
		break;

	case ITEM_WILD_ZBROJA:
		return SLOT_ZBROJA;
		break;
	case ITEM_WILD_NARAMIENNIKI:
		return SLOT_NARAMIENNIKI;
		break;
	case ITEM_WILD_REKAWICE:
		return SLOT_REKAWICE;
		break;
	case ITEM_WILD_NAGOLENNIKI:
		return SLOT_NAGOLENNIKI;
		break;
	case ITEM_WILD_BUTY:
		return SLOT_BUTY;
		break;
	case ITEM_WILD_HELM:
		return SLOT_HELM;
		break;
	default:
		return (ItemSlot)-1;
		break;
	}
}
#include "ItemDzwignia.h"


ItemDzwignia::ItemDzwignia(void)
{
	for (int i=0;i<LICZBA_SPOSOBOW_UZYCIA_DZWIGNI;i++)
	{
		zdarzenieGlobalne[i] = 0;
	}
	status=0;
}


ItemDzwignia::~ItemDzwignia(void)
{
}

int ItemDzwignia::dzwigniaStatus()
{
	return status;
}

void ItemDzwignia::dzwigniaUstawStatus(int nowy)
{
	status = nowy;
}

int ItemDzwignia::dzwigniaUzycie(SposobUzyciaDzwigni sposob)
{
	return zdarzenieGlobalne[sposob];
}

void ItemDzwignia::dzwigniaUstawZdarzenie(SposobUzyciaDzwigni sposob, int id)
{
	zdarzenieGlobalne[sposob] = id;
}
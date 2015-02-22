#include "item_dzwignia.h"


item_dzwignia::item_dzwignia(void)
{
	for (int i=0;i<LICZBA_SPOSOBOW_UZYCIA_DZWIGNI;i++)
	{
		zdarzenieGlobalne[i] = 0;
	}
	status=0;
}


item_dzwignia::~item_dzwignia(void)
{
}

int item_dzwignia::dzwigniaStatus()
{
	return status;
}

void item_dzwignia::dzwigniaUstawStatus(int nowy)
{
	status = nowy;
}

int item_dzwignia::dzwigniaUzycie(SposobUzyciaDzwigni sposob)
{
	return zdarzenieGlobalne[sposob];
}

void item_dzwignia::dzwigniaUstawZdarzenie(SposobUzyciaDzwigni sposob, int id)
{
	zdarzenieGlobalne[sposob] = id;
}
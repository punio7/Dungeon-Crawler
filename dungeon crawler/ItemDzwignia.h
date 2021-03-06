#pragma once
#include "Item.h"


class ItemDzwignia :
	public Item
{
public:
	ItemDzwignia(void);
	~ItemDzwignia(void);

	int dzwigniaUzycie(SposobUzyciaDzwigni sposob);
	int dzwigniaStatus();
	void dzwigniaUstawZdarzenie(SposobUzyciaDzwigni sposob, int id);
	void dzwigniaUstawStatus(int nowy);

	int zdarzenieGlobalne[LICZBA_SPOSOBOW_UZYCIA_DZWIGNI];	//numer zdarzenia globalnego uruchamianego przez d�wigni�, 0- nie uruchamia �adnego zdarzenia
								//indeks tablicy oznacza spos�b u�ycia dzwigni- patrz enum
	int status;					//status d�wigni standardowo 0-wy��czona 1-w��czona
};


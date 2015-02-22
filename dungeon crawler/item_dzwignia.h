#pragma once
#include "item.h"


class item_dzwignia :
	public Item
{
public:
	item_dzwignia(void);
	~item_dzwignia(void);

	int dzwigniaUzycie(SposobUzyciaDzwigni sposob);
	int dzwigniaStatus();
	void dzwigniaUstawZdarzenie(SposobUzyciaDzwigni sposob, int id);
	void dzwigniaUstawStatus(int nowy);

	int zdarzenieGlobalne[LICZBA_SPOSOBOW_UZYCIA_DZWIGNI];	//numer zdarzenia globalnego uruchamianego przez dŸwigniê, 0- nie uruchamia ¿adnego zdarzenia
								//indeks tablicy oznacza sposób u¿ycia dzwigni- patrz enum
	int status;					//status dŸwigni standardowo 0-wy³¹czona 1-w³¹czona
};


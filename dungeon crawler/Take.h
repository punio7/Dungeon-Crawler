#pragma once
#include "komenda.h"

class Item;
class ItemList;

class Take :
	public Komenda
{
public:
	Take(Gra *gra);
	~Take(void);
	void execute(ParseDTO argumenty);
	void manual();

	void TakePrzedmiot(Item *przedmiot, ItemList *lista);	//przemeiszcza podany przedmiot z podanej listy do inv gracz

	void TakePrzedmiotOtoczenie(wstring cel, int ktory);
	void TakePrzedmiotPojemnik(wstring cel1, int ktory1, wstring cel2, int ktory2);
	void TakeAllOtoczenie();
	void TakeAllPojemnik(wstring cel, int ktory);
	void zabierzZloto(Item* cel);
};


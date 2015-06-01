#pragma once

#include "Item.h"

;using namespace std;

class ItemContainer: public Item
{
public:
	ItemContainer();
	~ItemContainer();

	wstring examine();
	void lista_dodaj(Item* przedmiot);
	void lista_usun(Item* przedmiot);
	void lista_usunPierwszy();
	int zloto();
	void dodajZloto(int ilosc);
	void usunZloto(int ilosc);
	void ustawZamek(int id);
	int numerZamka();
	ItemList* getItemList();
	Item* lista_znajdz(wstring szukany, int ktory);
	Item* lista_znajdz(int ktory);
	bool lista_pusta();

	ItemList* lista;
	int zlotoIlosc;
	int zamek;			//id klucza potrzebnego do otworzenia pojemnika, 0-otwarte
};
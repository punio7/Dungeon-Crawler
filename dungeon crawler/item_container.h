#pragma once

#include "item.h"

;using namespace std;

class item_container: public Item
{
public:
	item_container();
	~item_container();

	string examine();
	void lista_dodaj(Item* przedmiot);
	void lista_usun(Item* przedmiot);
	void lista_usunPierwszy();
	int zloto();
	void dodajZloto(int ilosc);
	void usunZloto(int ilosc);
	void ustawZamek(int id);
	int numerZamka();
	ItemList* getItemList();
	Item* lista_znajdz(string szukany, int ktory);
	Item* lista_znajdz(int ktory);
	bool lista_pusta();

	ItemList* lista;
	int zlotoIlosc;
	int zamek;			//id klucza potrzebnego do otworzenia pojemnika, 0-otwarte
};
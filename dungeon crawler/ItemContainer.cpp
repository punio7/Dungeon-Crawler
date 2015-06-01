#include "ItemContainer.h"

ItemContainer::ItemContainer()
{
	Item::Item();
	typ = ITEM_CONTAINER;
	lista = new ItemList;
	zlotoIlosc = 0;
	zamek = 0;
}

ItemContainer::~ItemContainer()
{

}

wstring ItemContainer::examine()
{
	wstring temp;
	temp += opis;
	temp += L"\n\n";
	if (!zamek)	//jezeli nie jest zamkniety na klucz
	{
		temp += L"|^";
		temp += nazwa;
		temp += L" zawiera w sobie:\n";
		lista->wypisz(temp);
	}
	else
	{
		temp += L"\tPojemnik jest zamkniêty";
	}
	return temp;
}

void ItemContainer::lista_dodaj(Item* przedmiot)
{
	lista->dodaj(przedmiot);
}

void ItemContainer::lista_usun(Item* przedmiot)
{
	lista->usun(przedmiot);
}

void ItemContainer::lista_usunPierwszy()
{
	lista->usunPierwszy();
}

int ItemContainer::zloto()
{
	return zlotoIlosc;
}

void ItemContainer::dodajZloto(int ilosc)
{
	zlotoIlosc += ilosc;
}

void ItemContainer::usunZloto(int ilosc)
{
	if ((zlotoIlosc -= ilosc) < 0) zlotoIlosc = 0;
}

void ItemContainer::ustawZamek(int id)
{
	zamek = id;
}

int ItemContainer::numerZamka()
{
	return zamek;
}

bool ItemContainer::lista_pusta()
{
	return lista->pusta();
}

ItemList* ItemContainer::getItemList()
{
	return lista;
}

Item* ItemContainer::lista_znajdz(wstring szukany, int ktory)
{
	return lista->znajdz(szukany, ktory);
}

Item* ItemContainer::lista_znajdz(int ktory)
{
	return lista->znajdz(ktory);
}
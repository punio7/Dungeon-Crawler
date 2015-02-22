#include "item_container.h"

item_container::item_container()
{
	Item::Item();
	typ=ITEM_CONTAINER;
	lista=new ItemList;
	zlotoIlosc=0;
	zamek=0;
}

item_container::~item_container()
{

}

string item_container::examine()
{
	string temp;
	temp+=opis;
	temp+="\n\n";
	if (!zamek)	//jezeli nie jest zamkniety na klucz
	{
		temp+="|^";
		temp+=nazwa;
		temp+=" zawiera w sobie:\n";
		lista->wypisz(temp);
	}
	else
	{
		temp+="\tPojemnik jest zamkniêty";
	}
	return temp;
}

void item_container::lista_dodaj(Item* przedmiot)
{
	lista->dodaj(przedmiot);
}

void item_container::lista_usun(Item* przedmiot)
{
	lista->usun(przedmiot);
}

void item_container::lista_usunPierwszy()
{
	lista->usunPierwszy();
}

int item_container::zloto()
{
	return zlotoIlosc;
}

void item_container::dodajZloto(int ilosc)
{
	zlotoIlosc+=ilosc;
}

void item_container::usunZloto(int ilosc)
{
	if ( (zlotoIlosc-=ilosc) < 0) zlotoIlosc=0;
}

void item_container::ustawZamek(int id)
{
	zamek=id;
}

int item_container::numerZamka()
{
	return zamek;
}

bool item_container::lista_pusta()
{
	return lista->pusta();
}

ItemList* item_container::getItemList()
{
	return lista;
}

Item* item_container::lista_znajdz(string szukany, int ktory)
{
	return lista->znajdz(szukany, ktory);
}

Item* item_container::lista_znajdz(int ktory)
{
	return lista->znajdz(ktory);
}
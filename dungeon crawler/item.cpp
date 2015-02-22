#include "item.h"
#include "languageUtils.h"
#include "ItemSlot.h"
#include "playerMsg.h"

Staty::Staty()
{
	sil=0, zr=0, zw=0, wyt=0, zyw=0;
	atak=0, obrona=0, dmg=0, ochrona=0, pancerz=0, hp=0, cw=0;
}

ItemList::ItemList()
{

}

ItemList::~ItemList()
{

}

string ItemList::wypisz(ItemList_wypisz_tryb tryb)
{
	string temp;
	if (empty())
	{
		if (tryb!=WYPISZ_LOOK) temp+="\tOgólnie nic";
		return temp;
	}

	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		int ilosc = 1;
		temp+="\t";
		temp+=(*aktualny)->nazwa;
		iterator nastepny = aktualny;
		nastepny++;
		while (nastepny != end())
		{
			if ((*nastepny)->id == (*aktualny)->id)
			{
				aktualny = nastepny;
				nastepny++;
				ilosc++;
			}
			else
			{
				break;
			}
		}
		if (ilosc>1)
		{
			temp+=" (";
			temp+=intToStr(ilosc);
			temp+=")";
		}
		if (tryb==WYPISZ_LOOK) 
		{
			temp+=" ";
			temp+=(*aktualny)->idle;
		}
		if (nastepny != end())
			temp+="\n";
	}
	return temp;
}

void ItemList::wypisz(string& cel, ItemList_wypisz_tryb tryb)
{
	if (empty())
	{
		cel+="\tOgólnie nic.";
		return;
	}
	iterator aktualny;
	int num = 0;
	for (aktualny = begin(); aktualny != end(); aktualny++)
	{
		int ilosc=1;	//ilosc przedmiotow o takiej samej nazwie, jezeli >1 to bedzie wyswietlona w nawiasie
		num++;			//numer przedmiotu wyswietlany tylko w sklepie
		if (tryb == WYPISZ_SKLEP)
		{
			ostringstream ss;
			ss<<num<<'\t'<<(*aktualny)->wartosc;
			cel+=ss.str();
		}
		cel+="\t";
		cel+=(*aktualny)->nazwa;
		iterator nastepny = aktualny;
		nastepny++;
		while (nastepny != end())
		{
			if ((*nastepny)->id == (*aktualny)->id)
			{
				aktualny = nastepny;
				nastepny++;
				ilosc;;
			}
			else
			{
				break;
			}
		}
		if (ilosc>1) 
		{
			ostringstream ss;
			ss<<" ("<<ilosc<<")";
			cel+=ss.str();
		}
		if (nastepny != end())
			cel+='\n';
	}
}

Item* ItemList::znajdz(string szukany, int ktory)
{
	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if ((*aktualny)->nazwa.find(szukany) != -1) 
		{
			if (ktory<2) return *aktualny;
			else ktory--;
		}
	}

	return NULL;
}

Item* ItemList::znajdz(int ktory)
{
	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if (ktory<2) return *aktualny;
		else ktory--;
	}

	return NULL;
}

Item* ItemList::znajdz(int id, int ktory)
{
	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if ((*aktualny)->id == id) 
		{
			if (ktory<2) return *aktualny;
			else ktory--;
		}
	}

	return NULL;
}

list<Item*>::iterator ItemList::znajdzOstatni(int id)
{
	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if ((*aktualny)->id == id) 
		{
			iterator nastepny = aktualny;
			nastepny++;
			if (nastepny == end()) 
				return aktualny;
			if ( (*nastepny)->id != id ) return aktualny;
		}
	}

	return end();
}

list<Item*>::iterator ItemList::znajdzOstatni(string nazwa)
{
	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if ((*aktualny)->nazwa == nazwa) 
		{
			iterator nastepny = aktualny;
			nastepny++;
			if (nastepny == end()) 
				return aktualny;
			if ( (*nastepny)->nazwa != nazwa ) return aktualny;
		}
	}

	return end();
}

void ItemList::dodaj(Item* przedmiot)
{
	iterator aktualny = znajdzOstatni(przedmiot->nazwa);
	if (aktualny != end())	//insert wstawia przed, my chcemy wstawic za
	{
		aktualny++;
	}
	
	insert(aktualny, przedmiot);	
}

void ItemList::przenies(ItemList* lista)
{
	while (!lista->pusta())
	{
		dodaj(lista->front());
		lista->usunPierwszy();
	}
}

void ItemList::usun(Item* przedmiot)
{
	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if (*aktualny == przedmiot)
		{
			erase(aktualny);
			break;
		}
	}
}

void ItemList::usunPierwszy()
{
	pop_front();
}

bool ItemList::pusta()
{
	return empty();
}



Item::Item()
{
	nazwa="bezimienny przedmiot";
	rodzaj = RodzajRzeczownika::MESKI;
	opis="Brak opisu.";
	idle="le¿y tutaj";
	wartosc=0;
	typ=ITEM_UNKNOWN;
}

string Item::look()
{
	return opis;
}

string Item::examine()
{
	return opis;
}

void Item::ustaw_staty(int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw)
{

}

void Item::ustaw_wymagania(int sila, int zre, int zwi, int wyt, int zyw)
{

}

Staty Item::czytaj_staty()
{
	Staty *staty=new Staty;
	return *staty;
}

ItemSlot Item::getSlot()
{
	return (ItemSlot)-1;
}

int Item::wartoscSprzedazy()
{
	if (wartosc==0) return 0;	//wartosc 0 zawsze bedzie rowna 0
	if (wartosc==1) return 1;	//wartosc 1 nie jest zaokraglana w dol
	return (int)(wartosc * 0.5);
}

int Item::wartoscKupna()
{
	return wartosc;
}

bool Item::daSieWziac()
{
	if (typ==ITEM_STATIC_CONTAINER) return false;
	if (typ==ITEM_STATIC_QUEST) return false;
	if (typ==ITEM_DZWIGNIA) return false;
	return true;
}

bool Item::jestPojemnikiem()
{
	if ((typ==ITEM_STATIC_CONTAINER)||(typ==ITEM_CONTAINER)) return true;
	else return false;
}

bool Item::jestDzwignia()
{
	if (typ == ITEM_DZWIGNIA) return true;
	else return false;
}

bool Item::jestPancerzem()
{
	switch (typ)
	{
	case ITEM_ZBROJA:
		return true;
		break;
	case ITEM_NARAMIENNIKI:
		return true;
		break;
	case ITEM_REKAWICE:
		return true;
		break;
	case ITEM_NAGOLENNIKI:
		return true;
		break;
	case ITEM_BUTY:
		return true;
		break;
	case ITEM_HELM:
		return true;
		break;
	default:
		return false;
		break;
	}
}

bool Item::jestBronia()
{
	switch (typ)
	{
	case ITEM_1HWEAPON:
		return true;
		break;
	case ITEM_2HWEAPON:
		return true;
		break;
	default:
		return false;
		break;
	}
}

bool Item::jestTarcza()
{
	if (typ==ITEM_TARCZA) return true;
	else return false;
}

bool Item::jestMikstura()
{
	if (typ==ITEM_MIKSTURA) return true;
	else return false;
}

void Item::lista_dodaj(Item* przedmiot)
{

}

void Item::lista_usun(Item* przedmiot)
{

}

void Item::lista_usunPierwszy()
{

}

int Item::zloto()
{
	return 0;
}

void Item::dodajZloto(int ilosc)
{

}

void Item::usunZloto(int ilosc)
{

}

void Item::ustawZamek(int ids)
{

}

int Item::numerZamka()
{
	return 0;
}

bool Item::lista_pusta()
{
	return true;
}

ItemList* Item::getItemList()
{
	return NULL;
}

Item* Item::lista_znajdz(string szukany, int ktory)
{
	return NULL;
}

Item* Item::lista_znajdz(int ktory)
{
	return NULL;
}

int Item::dzwigniaUzycie(SposobUzyciaDzwigni sposob)
{
	return 0;
}

void Item::dzwigniaUstawZdarzenie(SposobUzyciaDzwigni sposob, int id)
{

}

int Item::dzwigniaStatus()
{
	return 0;
}

void Item::dzwigniaUstawStatus(int nowy)
{

}

bool Item::drink(Postac *postac)
{
	return false;
}
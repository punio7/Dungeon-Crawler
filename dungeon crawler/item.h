#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "ItemSlot.h"
#include "languageUtils.h"

;using namespace std;

class Postac;
enum ItemSlot;

enum ItemTyp
{
	ITEM_UNKNOWN,
	ITEM_QUEST,
	ITEM_STATIC_QUEST,
	ITEM_DZWIGNIA,
	ITEM_CONTAINER,
	ITEM_STATIC_CONTAINER,
	ITEM_1HWEAPON,
	ITEM_2HWEAPON,
	ITEM_TARCZA,
	ITEM_ZBROJA,
	ITEM_NARAMIENNIKI,
	ITEM_REKAWICE,
	ITEM_NAGOLENNIKI,
	ITEM_BUTY,
	ITEM_HELM,
	ITEM_KOSZULA,
	ITEM_SPODNIE,
	ITEM_PIERSCIEN,
	ITEM_NASZYJNIK,
	ITEM_WILD_1HWEAPON,
	ITEM_WILD_2HWEAPON,
	ITEM_WILD_TARCZA,
	ITEM_WILD_ZBROJA,
	ITEM_WILD_NARAMIENNIKI,
	ITEM_WILD_REKAWICE,
	ITEM_WILD_NAGOLENNIKI,
	ITEM_WILD_BUTY,
	ITEM_WILD_HELM,
	ITEM_MIKSTURA
};

enum ItemList_wypisz_tryb
{
	WYPISZ_LOOK,
	WYPISZ_INVENTORY,
	WYPISZ_EXAMINE,
	WYPISZ_SKLEP,
};

enum SposobUzyciaDzwigni
{
	DZWIGNIA_USE,
	DZWIGNIA_PULL,
	DZWIGNIA_PUSH,
	DZWIGNIA_TURN_LEFT,
	DZWIGNIA_TURN_RIGHT,
	LICZBA_SPOSOBOW_UZYCIA_DZWIGNI
};

class Staty
{
public:
	Staty();

	int sil, zr, zw, wyt, zyw;
	int atak, obrona, dmg, ochrona, pancerz, hp, cw;
};
class ItemList;

class Item
{
public:
	Item();

	virtual string look();
	virtual string examine();
	virtual void ustaw_staty(int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw);
	virtual void ustaw_wymagania(int sila, int zre, int zwi, int wyt, int zyw);
	virtual Staty czytaj_staty();
	virtual ItemSlot getSlot();	//jezeli dany przedmiot da sie wyekwipowac to zwraca slot ekwipunku, inaczej zwraca -1
	int wartoscSprzedazy();		//kiedy gracz chce sprzedac taki item
	int wartoscKupna();			//kiedy gracz chce kupic taki item
	bool daSieWziac();
	bool jestPojemnikiem();
	bool jestDzwignia();
	bool jestPancerzem();
	bool jestBronia();
	bool jestTarcza();
	bool jestMikstura();

	//dla typu container
	virtual void lista_dodaj(Item* przedmiot);
	virtual void lista_usun(Item* przedmiot);
	virtual void lista_usunPierwszy();
	virtual int zloto();
	virtual void dodajZloto(int ilosc);
	virtual void usunZloto(int ilosc);
	//id klucza do zamka, 0-otwarte
	virtual void ustawZamek(int id);
	//id klucza do zamka, 0-otwarte
	virtual int numerZamka();
	virtual ItemList* getItemList();
	virtual Item* lista_znajdz(string szukany, int ktory);
	virtual Item* lista_znajdz(int ktory);
	virtual bool lista_pusta();

	//dla typu dzwigia

	//zwraca numer zdarzenia globalnego dla danej akcji
	virtual int dzwigniaUzycie(SposobUzyciaDzwigni sposob);
	virtual void dzwigniaUstawZdarzenie(SposobUzyciaDzwigni sposob, int id);
	//zwraca status dzwigni
	virtual int dzwigniaStatus();
	virtual void dzwigniaUstawStatus(int nowy);

	//dla typu mikstura

	//zwraca true jezeli mikstura ma zostac zniszczona
	virtual bool drink(Postac *postac);

	int id;
	string nazwa;	//identyfikacyjna nazwa przedmiotu napisana z ma³ej litery
	RodzajRzeczownika::RodzajRzeczownikaEnum rodzaj;
	string opis;	//d³u¿szy opis wyœwietlany przy komendzie look
	string idle;	//krótki opis przedmiotu znajdujacego sie w pomeiszczeniu np. le¿y na ziemi
	ItemTyp typ;

	int wartosc;	//wartoœæ przedmiotu w z³ocie
};

class ItemList : public list<Item*>
{
public:
	ItemList();
	~ItemList();
	string wypisz(ItemList_wypisz_tryb tryb=WYPISZ_LOOK);
	void wypisz(string& cel, ItemList_wypisz_tryb tryb=WYPISZ_EXAMINE);		//wypisuje liste przedmiotow do stringu podanego w argumencie
	void dodaj(Item* przedmiot);
	//przenosi Itemy z podanej listy do obecnej listy
	void przenies(ItemList* lista);
	//usuwa element z listy ale nie kasuje go z pamieci
	void usun(Item* przedmiot);	
	//usuwa z listy pierwszy element, ale nie kasuje z pamiêci
	void usunPierwszy();
	//true je¿eli lista jest pusta
	bool pusta();					
	//zwraca wskaŸnik na najdalszy element listy zawieraj¹cy dany przedmiot
	list<Item*>::iterator znajdzOstatni(int id);
	list<Item*>::iterator znajdzOstatni(string nazwa);
	//zwraca wskaŸnik na przedmiot z listy o zadanej nazwie, NULL jezeli nie ma takiego
	Item* znajdz(string szukany, int ktory=1);
	//zwraca przedmiot bêd¹cy na ktory-m miejscu na liscie zaczynajac od 1
	Item* znajdz(int ktory);
	//zwraca wskaŸnik  na przedmiot o zadanym id z listy, NULL je¿eli nie ma takiego
	Item* znajdz(int id, int ktory);
};
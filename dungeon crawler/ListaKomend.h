#pragma once
#include "EnumKomendy.h"
#include "Komenda.h"

class Buy;
class Cheat;
class Condition;
class Consider;
class Down;
class Drink;
class Drop;
class Equipment;
class East;
class Examine;
class List;
class Look;
class Go;
class Hold;
class Inventory;
class Journal;
class Kill;
class Manual;
class Map;
class North;
class Offer;
class Open;
class Pull;
class Push;
class Put;
class Quit;
class Remove;
class Sell;
class Scan;
class Score;
class South;
class Take;
class Talk;
class Test;
class Train;
class Turn;
class Unlock;
class Up;
class Wear;
class West;
class Wield;

class Gra;

//czynnosci do stworzenia nowej komendy:
//1. nowa klasa komendy na podstawie komendaTemplate
//2. dodanie do enuma EnumKomendy
//3. utworzenie obiektu w tablicy ListaKomend::komendy
//4. dodanie komendy w create_command_tree()

class ListaKomend
{
public:			
	Komenda *komendy[LICZBA_KOMEND];

	ListaKomend(Gra* gra);
	~ListaKomend(void);
};

extern ListaKomend *listaKomend;
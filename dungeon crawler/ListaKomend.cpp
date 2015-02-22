#include "ListaKomend.h"
#include "Buy.h"
#include "Cheat.h"
#include "Condition.h"
#include "Consider.h"
#include "Down.h"
#include "Drink.h"
#include "Drop.h"
#include "Equipment.h"
#include "East.h"
#include "Examine.h"
#include "List.h"
#include "Look.h"
#include "Go.h"
#include "Hold.h"
#include "Inventory.h"
#include "Journal.h"
#include "Kill.h"
#include "Manual.h"
#include "Map.h"
#include "North.h"
#include "Offer.h"
#include "Open.h"
#include "Pull.h"
#include "Push.h"
#include "Put.h"
#include "Quit.h"
#include "Remove.h"
#include "Sell.h"
#include "Scan.h"
#include "Score.h"
#include "South.h"
#include "Take.h"
#include "Talk.h"
#include "Test.h"
#include "Train.h"
#include "Turn.h"
#include "Unlock.h"
#include "Up.h"
#include "Wear.h"
#include "West.h"
#include "Wield.h"

ListaKomend *listaKomend;

ListaKomend::ListaKomend(Gra *gra)
{
	for (int i = COMM_WRONG; i < LICZBA_KOMEND; i++)
	{
		komendy[i] = NULL;
	}

	komendy[(int)COMM_WRONG] = new Komenda(gra);
	komendy[(int)COMM_NOCOMM] = new Komenda(gra);

	komendy[(int)COMM_BUY] = new Buy(gra);
	komendy[(int)COMM_CHEAT] = new Cheat(gra);
	komendy[(int)COMM_CONDITION] = new Condition(gra);
	komendy[(int)COMM_CONSIDER] = new Consider(gra);
	komendy[(int)COMM_DOWN] = new Down(gra);
	komendy[(int)COMM_DRINK] = new Drink(gra);
	komendy[(int)COMM_DROP] = new Drop(gra);
	komendy[(int)COMM_EAST] = new East(gra);
	komendy[(int)COMM_EQUIPMENT] = new Equipment(gra);
	komendy[(int)COMM_EXAMINE] = new Examine(gra);
	komendy[(int)COMM_GO] = new Go(gra);
	komendy[(int)COMM_HOLD] = new Hold(gra);
	komendy[(int)COMM_INVENTORY] = new Inventory(gra);
	komendy[(int)COMM_JOURNAL] = new Journal(gra);
	komendy[(int)COMM_KILL] = new Kill(gra);
	komendy[(int)COMM_LIST] = new List(gra);
	komendy[(int)COMM_LOOK] = new Look(gra);
	komendy[(int)COMM_MANUAL] = new Manual(gra);
	komendy[(int)COMM_MAP] = new Map(gra);
	komendy[(int)COMM_NORTH] = new North(gra);
	komendy[(int)COMM_OFFER] = new Offer(gra);
	komendy[(int)COMM_OPEN] = new Open(gra);
	komendy[(int)COMM_PULL] = new Pull(gra);
	komendy[(int)COMM_PUSH] = new Push(gra);
	komendy[(int)COMM_PUT] = new Put(gra);
	komendy[(int)COMM_QUIT] = new Quit(gra);
	komendy[(int)COMM_REMOVE] = new Remove(gra);
	komendy[(int)COMM_SCAN] = new Scan(gra);
	komendy[(int)COMM_SELL] = new Sell(gra);
	komendy[(int)COMM_SCORE] = new Score(gra);
	komendy[(int)COMM_SOUTH] = new South(gra);
	komendy[(int)COMM_TAKE] = new Take(gra);
	komendy[(int)COMM_TALK] = new Talk(gra);
	komendy[(int)COMM_TEST] = new Test(gra);
	komendy[(int)COMM_TRAIN] = new Train(gra);
	komendy[(int)COMM_TURN] = new Turn(gra);
	komendy[(int)COMM_UNLOCK] = new Unlock(gra);
	komendy[(int)COMM_UP] = new Up(gra);
	komendy[(int)COMM_WEAR] = new Wear(gra);
	komendy[(int)COMM_WEST] = new West(gra);
	komendy[(int)COMM_WIELD] = new Wield(gra);
}


ListaKomend::~ListaKomend(void)
{
	for (int i = 0; i < LICZBA_KOMEND; i++)
	{
		delete komendy[i];
	}
}

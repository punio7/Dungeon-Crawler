#include "Open.h"
#include "gra.h"
#include "Lokacja.h"

Open::Open(Gra *gra):
	Komenda(gra)
{
	nazwa="open";
}


Open::~Open(void)
{
}

void Open::execute(ParseDTO argumenty)
{
	KierunekSwiata kierunek = argumenty.kierunek1;
	Lokacja *polozenie = gra->gracz.polozenie;
	if (kierunek == NORTH || kierunek == SOUTH || kierunek == WEST || kierunek == EAST || kierunek == UP || kierunek == DOWN)
	{
		switch ( ((polozenie)->zamek)[kierunek] )
		{
		case 0:
			playerMsg("Tam nie ma czego otworzy�.");
			return;
		case -1:
			playerMsg("Tam nie ma czego otworzy�.");
			return;
		case 1:
			playerMsg("Otwierasz przej�cie.");
			(polozenie->zamek)[kierunek] = 0;
			(((polozenie->wyjscie)[kierunek])->zamek)[kierunekPrzeciwny(kierunek)] = 0;	//jezeli otwieramy drzwi od poludnia
			return;																			//to od polnocy tez beda otwarte
		default:
			playerMsg("Zamkni�te na klucz.");
			return;
		}
	}
	else
	{
		playerMsg("Chcesz otworzy� przejscie w kt�rym kierunku?");
	}
}

void Open::manual()
{
	playerMsg("Synonimy:\n"
				"   open(o)\n\n"
				"U�ycia:\n\n"
				"   open <kierunek_�wiata> - gracz podejmie pr�b� otworzenia przej�cia w danym kierunku. Oczywi�cie przej�cie mo�e okaza� si� zamkni�te na klucz.\n\n"
				"Sprawd� r�wnie�:\n"
				"   unlock, north, south, west, east, up, down");
}
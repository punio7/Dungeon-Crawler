#include "Open.h"
#include "Gra.h"
#include "Lokacja.h"

Open::Open(Gra *gra):
	Komenda(gra)
{
	nazwa = L"open";
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
			playerMsg(L"Tam nie ma czego otworzy�.");
			return;
		case -1:
			playerMsg(L"Tam nie ma czego otworzy�.");
			return;
		case 1:
			playerMsg(L"Otwierasz przej�cie.");
			(polozenie->zamek)[kierunek] = 0;
			(((polozenie->wyjscie)[kierunek])->zamek)[kierunekPrzeciwny(kierunek)] = 0;	//jezeli otwieramy drzwi od poludnia
			return;																			//to od polnocy tez beda otwarte
		default:
			playerMsg(L"Zamkni�te na klucz.");
			return;
		}
	}
	else
	{
		playerMsg(L"Chcesz otworzy� przejscie w kt�rym kierunku?");
	}
}

void Open::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   open(o)\n\n"
			 L"U�ycia:\n\n"
			 L"   open <kierunek_�wiata> - gracz podejmie pr�b� otworzenia przej�cia w danym kierunku. Oczywi�cie przej�cie mo�e okaza� si� zamkni�te na klucz.\n\n"
			 L"Sprawd� r�wnie�:\n"
			 L"   unlock, north, south, west, east, up, down");
}
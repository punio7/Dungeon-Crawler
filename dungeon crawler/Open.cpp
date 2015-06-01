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
			playerMsg(L"Tam nie ma czego otworzyæ.");
			return;
		case -1:
			playerMsg(L"Tam nie ma czego otworzyæ.");
			return;
		case 1:
			playerMsg(L"Otwierasz przejœcie.");
			(polozenie->zamek)[kierunek] = 0;
			(((polozenie->wyjscie)[kierunek])->zamek)[kierunekPrzeciwny(kierunek)] = 0;	//jezeli otwieramy drzwi od poludnia
			return;																			//to od polnocy tez beda otwarte
		default:
			playerMsg(L"Zamkniête na klucz.");
			return;
		}
	}
	else
	{
		playerMsg(L"Chcesz otworzyæ przejscie w którym kierunku?");
	}
}

void Open::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   open(o)\n\n"
			 L"U¿ycia:\n\n"
			 L"   open <kierunek_œwiata> - gracz podejmie próbê otworzenia przejœcia w danym kierunku. Oczywiœcie przejœcie mo¿e okazaæ siê zamkniête na klucz.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   unlock, north, south, west, east, up, down");
}
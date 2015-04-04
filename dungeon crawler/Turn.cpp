#include "Turn.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"

Turn::Turn(Gra *gra):
	Komenda(gra)
{
	nazwa = L"turn";
}


Turn::~Turn(void)
{
}

void Turn::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())
	{
		playerMsg(L"W kt�r� stron� chcesz kr�ci�.?");
		return;
	}

	wstring kierunek;
	switch (argumenty.argument1[0])
	{
	case 'l':
		kierunek = L"left";
		if (kierunek.find(argumenty.argument1, 0) == -1)
		{
			playerMsg(L"W kt�r� stron� chcesz kr�ci�?");
			return;
		}
		break;
	case 'r':
		kierunek = L"right";
		if (kierunek.find(argumenty.argument1, 0) == -1)
		{
			playerMsg(L"W kt�r� stron� chcesz kr�ci�?");
			return;
		}
		break;
	default:
		playerMsg(L"W kt�r� stron� chcesz kr�ci�?");
		return;
	}
	
	if (argumenty.argument2.empty())
	{
		playerMsg(L"Co chcesz przekr�ci�?");
		return;
	}

	Item* dzwignia = gra->gracz.polozenie->przedmioty->znajdz(argumenty.argument2);

	if (!dzwignia)
	{
		playerMsg(L"Tutaj nie ma �adnego �adnego |0.", argumenty.argument2);
		return;
	}

	if (kierunek == L"left")
	{
		if (!dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_LEFT))
		{
			playerMsg(L"Tego nie da si� przekr�ci� w lewo.");
			return;
		}

		gra->zdarzenieGlobalne(dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_LEFT));
		return;
	}
	else
	{
		if (!dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_RIGHT))
		{
			playerMsg(L"Tego nie da si� przekr�ci� w prawo.");
			return;
		}

		gra->zdarzenieGlobalne(dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_RIGHT));
		return;
	}

	
}

void Turn::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   turn(tu)\n\n"
			 L"U�ycia:\n\n"
			 L"   turn <kierunek> <nazwa_przedmiotu> - gracz pr�buje kr�ci� wskazan� wajch� we wskazanym kierunku. Kierunkiem mo�e by�: left(l), right(r).\n\n"
			 L"Sprawd� r�wnie�:\n"
			 L"   push, pull");
}
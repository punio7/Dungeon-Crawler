#include "Turn.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"

Turn::Turn(Gra *gra):
	Komenda(gra)
{
	nazwa="turn";
}


Turn::~Turn(void)
{
}

void Turn::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())
	{
		playerMsg("W kt�r� stron� chcesz kr�ci�.?");
		return;
	}

	string kierunek;
	switch (argumenty.argument1[0])
	{
	case 'l':
		kierunek = "left";
		if (kierunek.find(argumenty.argument1, 0) == -1)
		{
			playerMsg("W kt�r� stron� chcesz kr�ci�?");
			return;
		}
		break;
	case 'r':
		kierunek = "right";
		if (kierunek.find(argumenty.argument1, 0) == -1)
		{
			playerMsg("W kt�r� stron� chcesz kr�ci�?");
			return;
		}
		break;
	default:
		playerMsg("W kt�r� stron� chcesz kr�ci�?");
		return;
	}
	
	if (argumenty.argument2.empty())
	{
		playerMsg("Co chcesz przekr�ci�?");
		return;
	}

	Item* dzwignia = gra->gracz.polozenie->przedmioty->znajdz(argumenty.argument2);

	if (!dzwignia)
	{
		playerMsg("Tutaj nie ma �adnego �adnego |0.", argumenty.argument2);
		return;
	}

	if (kierunek == "left")
	{
		if (!dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_LEFT))
		{
			playerMsg("Tego nie da si� przekr�ci� w lewo.");
			return;
		}

		gra->zdarzenieGlobalne(dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_LEFT));
		return;
	}
	else
	{
		if (!dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_RIGHT))
		{
			playerMsg("Tego nie da si� przekr�ci� w prawo.");
			return;
		}

		gra->zdarzenieGlobalne(dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_RIGHT));
		return;
	}

	
}

void Turn::manual()
{
	playerMsg("Synonimy:\n"
				"   turn(tu)\n\n"
				"U�ycia:\n\n"
				"   turn <kierunek> <nazwa_przedmiotu> - gracz pr�buje kr�ci� wskazan� wajch� we wskazanym kierunku. Kierunkiem mo�e by�: left(l), right(r).\n\n"
				"Sprawd� r�wnie�:\n"
				"   push, pull");
}
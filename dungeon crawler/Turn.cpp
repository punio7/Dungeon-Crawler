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
		playerMsg("W któr¹ stronê chcesz krêciæ.?");
		return;
	}

	string kierunek;
	switch (argumenty.argument1[0])
	{
	case 'l':
		kierunek = "left";
		if (kierunek.find(argumenty.argument1, 0) == -1)
		{
			playerMsg("W któr¹ stronê chcesz krêciæ?");
			return;
		}
		break;
	case 'r':
		kierunek = "right";
		if (kierunek.find(argumenty.argument1, 0) == -1)
		{
			playerMsg("W któr¹ stronê chcesz krêciæ?");
			return;
		}
		break;
	default:
		playerMsg("W któr¹ stronê chcesz krêciæ?");
		return;
	}
	
	if (argumenty.argument2.empty())
	{
		playerMsg("Co chcesz przekrêciæ?");
		return;
	}

	Item* dzwignia = gra->gracz.polozenie->przedmioty->znajdz(argumenty.argument2);

	if (!dzwignia)
	{
		playerMsg("Tutaj nie ma ¿adnego ¿adnego |0.", argumenty.argument2);
		return;
	}

	if (kierunek == "left")
	{
		if (!dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_LEFT))
		{
			playerMsg("Tego nie da siê przekrêciæ w lewo.");
			return;
		}

		gra->zdarzenieGlobalne(dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_LEFT));
		return;
	}
	else
	{
		if (!dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_RIGHT))
		{
			playerMsg("Tego nie da siê przekrêciæ w prawo.");
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
				"U¿ycia:\n\n"
				"   turn <kierunek> <nazwa_przedmiotu> - gracz próbuje krêciæ wskazan¹ wajch¹ we wskazanym kierunku. Kierunkiem mo¿e byæ: left(l), right(r).\n\n"
				"SprawdŸ równie¿:\n"
				"   push, pull");
}
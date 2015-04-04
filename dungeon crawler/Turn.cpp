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
		playerMsg(L"W któr¹ stronê chcesz krêciæ.?");
		return;
	}

	wstring kierunek;
	switch (argumenty.argument1[0])
	{
	case 'l':
		kierunek = L"left";
		if (kierunek.find(argumenty.argument1, 0) == -1)
		{
			playerMsg(L"W któr¹ stronê chcesz krêciæ?");
			return;
		}
		break;
	case 'r':
		kierunek = L"right";
		if (kierunek.find(argumenty.argument1, 0) == -1)
		{
			playerMsg(L"W któr¹ stronê chcesz krêciæ?");
			return;
		}
		break;
	default:
		playerMsg(L"W któr¹ stronê chcesz krêciæ?");
		return;
	}
	
	if (argumenty.argument2.empty())
	{
		playerMsg(L"Co chcesz przekrêciæ?");
		return;
	}

	Item* dzwignia = gra->gracz.polozenie->przedmioty->znajdz(argumenty.argument2);

	if (!dzwignia)
	{
		playerMsg(L"Tutaj nie ma ¿adnego ¿adnego |0.", argumenty.argument2);
		return;
	}

	if (kierunek == L"left")
	{
		if (!dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_LEFT))
		{
			playerMsg(L"Tego nie da siê przekrêciæ w lewo.");
			return;
		}

		gra->zdarzenieGlobalne(dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_LEFT));
		return;
	}
	else
	{
		if (!dzwignia->dzwigniaUzycie(DZWIGNIA_TURN_RIGHT))
		{
			playerMsg(L"Tego nie da siê przekrêciæ w prawo.");
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
			 L"U¿ycia:\n\n"
			 L"   turn <kierunek> <nazwa_przedmiotu> - gracz próbuje krêciæ wskazan¹ wajch¹ we wskazanym kierunku. Kierunkiem mo¿e byæ: left(l), right(r).\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   push, pull");
}
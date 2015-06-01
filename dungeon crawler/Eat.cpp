#include "Eat.h"
#include "Gra.h"
#include "Item.h"

Eat::Eat(Gra *gra) :
Komenda(gra)
{
	nazwa = L"eat";
}


Eat::~Eat(void)
{
}

void Eat::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;

	if (argumenty.argument1.empty())
	{
		playerMsg(L"Co chcesz zjeœæ?");
		return;
	}

	Item* jedzonko = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);

	if (jedzonko == NULL)
	{
		playerMsg(L"Nie masz przy sobie czegoœ takiego jak |0.", argumenty.argument1);
		return;
	}

	if (!jedzonko->jestJedzeniem())
	{
		playerMsg(L"|^|0 nie jest jedzeniem!", jedzonko->nazwa);
		return;
	}

	playerMsg(L"Zjadasz |0.", jedzonko->nazwa);
	bool destroy = jedzonko->drink(&gracz);
	gracz.przelicz();
	if (destroy)
	{
		gracz.przedmioty->usun(jedzonko);
		delete jedzonko;
	}
}

void Eat::manual()
{
	playerMsg(L"Synonimy:\n"
		L"   Eat(eat)\n\n"
		L"U¿ycia:\n\n"
		L"   Eat <nazwa_jedzonka> - zjada wskazane jedzenie. Musi siê ono znajdowaæ w inwentarzu.\n\n"
		L"SprawdŸ równie¿:\n"
		L"   condition drink");
}
#include "Condition.h"
#include "gra.h"
#include "status.h"

Condition::Condition(Gra *gra):
	Komenda(gra)
{
	nazwa = "condition";
}


Condition::~Condition(void)
{
}

void Condition::execute(ParseDTO argumenty)
{
	playerMsg(gra->gracz.statusy->wypisz());
}

void Condition::manual()
{
	playerMsg("Synonimy:\n"
				"   condition(c)\n\n"
				"U�ycia:\n\n"
				"   condition - wy�wietla list� efekt�w wp�ywaj�cych na gracza.\n\n"
				"Sprawd� r�wnie�:\n"
				"   drink");
}
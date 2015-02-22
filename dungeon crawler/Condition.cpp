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
				"U¿ycia:\n\n"
				"   condition - wyœwietla listê efektów wp³ywaj¹cych na gracza.\n\n"
				"SprawdŸ równie¿:\n"
				"   drink");
}
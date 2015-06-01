#include "Condition.h"
#include "Gra.h"
#include "Status.h"

Condition::Condition(Gra *gra):
	Komenda(gra)
{
	nazwa = L"condition";
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
	playerMsg(L"Synonimy:\n"
				L"   condition(c)\n\n"
				L"U¿ycia:\n\n"
				L"   condition - wyœwietla listê efektów wp³ywaj¹cych na gracza.\n\n"
				L"SprawdŸ równie¿:\n"
				L"   drink");
}
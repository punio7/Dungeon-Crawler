#include "Inventory.h"
#include "gra.h"
#include "item.h"

Inventory::Inventory(Gra *gra):
	Komenda(gra)
{
	nazwa = L"inventory";
}


Inventory::~Inventory(void)
{
}

void Inventory::execute(ParseDTO argumenty)
{
	playerMsg(L"Obecnie przy sobie posiadasz:");
	playerMsg(gra->gracz.przedmioty->wypisz(WYPISZ_INVENTORY));
}

void Inventory::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   inventory(i)\n\n"
			 L"U¿ycia:\n\n"
			 L"   inventory - wyœwietla posiadane przez gracza przedmioty, z pominiêciem wyposa¿enia.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   equipment, wear, wield, hold, remove");
}

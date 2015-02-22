#include "Inventory.h"
#include "gra.h"
#include "item.h"

Inventory::Inventory(Gra *gra):
	Komenda(gra)
{
	nazwa="inventory";
}


Inventory::~Inventory(void)
{
}

void Inventory::execute(ParseDTO argumenty)
{
	playerMsg("Obecnie przy sobie posiadasz:");
	playerMsg(gra->gracz.przedmioty->wypisz(WYPISZ_INVENTORY));
}

void Inventory::manual()
{
	playerMsg("Synonimy:\n"
				"   inventory(i)\n\n"
				"U¿ycia:\n\n"
				"   inventory - wyœwietla posiadane przez gracza przedmioty, z pominiêciem wyposa¿enia.\n\n"
				"SprawdŸ równie¿:\n"
				"   equipment, wear, wield, hold, remove");
}

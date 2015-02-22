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
				"U�ycia:\n\n"
				"   inventory - wy�wietla posiadane przez gracza przedmioty, z pomini�ciem wyposa�enia.\n\n"
				"Sprawd� r�wnie�:\n"
				"   equipment, wear, wield, hold, remove");
}

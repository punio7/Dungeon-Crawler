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
			 L"U�ycia:\n\n"
			 L"   inventory - wy�wietla posiadane przez gracza przedmioty, z pomini�ciem wyposa�enia.\n\n"
			 L"Sprawd� r�wnie�:\n"
			 L"   equipment, wear, wield, hold, remove");
}

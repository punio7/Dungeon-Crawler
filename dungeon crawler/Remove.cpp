#include "Remove.h"
#include "Gra.h"
#include "Item.h"

Remove::Remove(Gra *gra):
	Komenda(gra)
{
	nazwa = L"remove";
}


Remove::~Remove(void)
{
}

void Remove::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;

	if (argumenty.argument1.empty())
	{
		playerMsg(L"Co chcesz zdj��?");
		return;
	}

	if (argumenty.argument1 != L"all")
	{
		ItemSlot slot = gracz.znajdzEQ(argumenty.argument1, argumenty.ktory1);
		if (slot == -1)
		{
			playerMsg(L"Aktualnie nie u�ywasz �adnego |0.", argumenty.argument1);
			return;
		}
		remove(slot); 
	}
	else
	{
		for (int slot = SLOT_ZBROJA; slot < SLOT_ILOSC; slot++)
		{
			remove((ItemSlot)slot);
		}
	}
	gracz.przelicz();
}

void Remove::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   remove(r)\n\n"
			 L"U�ycia:\n\n"
			 L"   remove <nazwa_przedmiotu> - gracz przestaje u�ywa�/nosi� wskazany przedmiot z ekwipunku i odk�ada go do inwentarza.\n\n"
			 L"Sprawd� r�wnie�:\n"
			 L"   inventory, equipment, wear, wield, hold");
}

void Remove::remove(ItemSlot slot)
{
	Gracz &gracz = gra->gracz;

	if (gracz.eq[slot] == NULL)
		return;

	if (gracz.eq[slot]->jestPancerzem()) 
		playerMsg(L"Zdejmujesz |0.", gracz.eq[slot]->nazwa);
	else 
		playerMsg(L"Przestajesz dzier�y� |0.", gracz.eq[slot]->nazwa);
	gracz.przedmioty->dodaj(gracz.eq[slot]);
	gracz.eq[slot]=NULL;
}
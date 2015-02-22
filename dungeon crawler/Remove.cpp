#include "Remove.h"
#include "gra.h"
#include "item.h"

Remove::Remove(Gra *gra):
	Komenda(gra)
{
	nazwa="remove";
}


Remove::~Remove(void)
{
}

void Remove::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;

	if (argumenty.argument1.empty())
	{
		playerMsg("Co chcesz zdj¹æ?");
		return;
	}

	if (argumenty.argument1 != "all")
	{
		ItemSlot slot = gracz.znajdzEQ(argumenty.argument1, argumenty.ktory1);
		if (slot == -1)
		{
			playerMsg("Aktualnie nie u¿ywasz ¿adnego |0.", argumenty.argument1);
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
	playerMsg("Synonimy:\n"
				"   remove(r)\n\n"
				"U¿ycia:\n\n"
				"   remove <nazwa_przedmiotu> - gracz przestaje u¿ywaæ/nosiæ wskazany przedmiot z ekwipunku i odk³ada go do inwentarza.\n\n"
				"SprawdŸ równie¿:\n"
				"   inventory, equipment, wear, wield, hold");
}

void Remove::remove(ItemSlot slot)
{
	Gracz &gracz = gra->gracz;

	if (gracz.eq[slot] == NULL)
		return;

	if (gracz.eq[slot]->jestPancerzem()) 
		playerMsg("Zdejmujesz |0.", gracz.eq[slot]->nazwa);
	else 
		playerMsg("Przestajesz dzier¿yæ |0.", gracz.eq[slot]->nazwa);
	gracz.przedmioty->dodaj(gracz.eq[slot]);
	gracz.eq[slot]=NULL;
}
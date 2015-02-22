#include "Push.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"

Push::Push(Gra *gra):
	Komenda(gra)
{
	nazwa="push";
}


Push::~Push(void)
{
}

void Push::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())
	{
		playerMsg("Co chcesz nacisn�� b�d� pchn��?");
		return;
	}

	Item* dzwignia = gra->gracz.polozenie->przedmioty->znajdz(argumenty.argument1);

	if (!dzwignia)
	{
		playerMsg("Tutaj nie ma �adnego �adnego |0.", argumenty.argument1);
		return;
	}

	if (!dzwignia->dzwigniaUzycie(DZWIGNIA_PUSH))
	{
		playerMsg("Tego nie da si� ani nacisn�� ani pchn��.");
		return;
	}

	gra->zdarzenieGlobalne(dzwignia->dzwigniaUzycie(DZWIGNIA_PUSH));
}

void Push::manual()
{
	playerMsg("Synonimy:\n"
				"   push(pus)\n\n"
				"U�ycia:\n\n"
				"   push <nazwa_przedmiotu> - gracz podejmie pr�b� naci�ni�cia albo pchni�cia wskazanego przedmiotu.\n\n"
				"Sprawd� r�wnie�:\n"
				"   pull, turn");
}
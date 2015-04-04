#include "Push.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"

Push::Push(Gra *gra):
	Komenda(gra)
{
	nazwa = L"push";
}


Push::~Push(void)
{
}

void Push::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())
	{
		playerMsg(L"Co chcesz nacisn�� b�d� pchn��?");
		return;
	}

	Item* dzwignia = gra->gracz.polozenie->przedmioty->znajdz(argumenty.argument1);

	if (!dzwignia)
	{
		playerMsg(L"Tutaj nie ma �adnego �adnego |0.", argumenty.argument1);
		return;
	}

	if (!dzwignia->dzwigniaUzycie(DZWIGNIA_PUSH))
	{
		playerMsg(L"Tego nie da si� ani nacisn�� ani pchn��.");
		return;
	}

	gra->zdarzenieGlobalne(dzwignia->dzwigniaUzycie(DZWIGNIA_PUSH));
}

void Push::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   push(pus)\n\n"
			 L"U�ycia:\n\n"
			 L"   push <nazwa_przedmiotu> - gracz podejmie pr�b� naci�ni�cia albo pchni�cia wskazanego przedmiotu.\n\n"
			 L"Sprawd� r�wnie�:\n"
			 L"   pull, turn");
}
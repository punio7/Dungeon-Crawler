#include "Pull.h"
#include "Gra.h"
#include "Item.h"
#include "Lokacja.h"

Pull::Pull(Gra *gra):
	Komenda(gra)
{
	nazwa = L"pull";
}


Pull::~Pull(void)
{
}

void Pull::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())
	{
		playerMsg(L"Co chcesz poci¹gn¹æ?");
		return;
	}

	Item* dzwignia = gra->gracz.polozenie->przedmioty->znajdz(argumenty.argument1);

	if (!dzwignia)
	{
		playerMsg(L"Tutaj nie ma ¿adnego ¿adnego |0.", argumenty.argument1);
		return;
	}

	if (!dzwignia->dzwigniaUzycie(DZWIGNIA_PULL))
	{
		playerMsg(L"To nic nie da.");
		return;
	}

	gra->zdarzenieGlobalne(dzwignia->dzwigniaUzycie(DZWIGNIA_PULL));
}

void Pull::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   pull(pul)\n\n"
			 L"U¿ycia:\n\n"
			 L"   pull <nazwa_przedmiotu> - gracz podejmie próbê pociagniêcia za wskazany przedmiot. Mo¿e to byæ lina, dŸwignia albo coœ innego znajdujacego siê w lokacji gracza.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   push, turn");
}
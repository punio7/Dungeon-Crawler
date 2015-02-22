#include "Pull.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"

Pull::Pull(Gra *gra):
	Komenda(gra)
{
	nazwa="pull";
}


Pull::~Pull(void)
{
}

void Pull::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())
	{
		playerMsg("Co chcesz poci¹gn¹æ?");
		return;
	}

	Item* dzwignia = gra->gracz.polozenie->przedmioty->znajdz(argumenty.argument1);

	if (!dzwignia)
	{
		playerMsg("Tutaj nie ma ¿adnego ¿adnego |0.", argumenty.argument1);
		return;
	}

	if (!dzwignia->dzwigniaUzycie(DZWIGNIA_PULL))
	{
		playerMsg("To nic nie da.");
		return;
	}

	gra->zdarzenieGlobalne(dzwignia->dzwigniaUzycie(DZWIGNIA_PULL));
}

void Pull::manual()
{
	playerMsg("Synonimy:\n"
				"   pull(pul)\n\n"
				"U¿ycia:\n\n"
				"   pull <nazwa_przedmiotu> - gracz podejmie próbê pociagniêcia za wskazany przedmiot. Mo¿e to byæ lina, dŸwignia albo coœ innego znajdujacego siê w lokacji gracza.\n\n"
				"SprawdŸ równie¿:\n"
				"   push, turn");
}
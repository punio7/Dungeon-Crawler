#include "Drop.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"

Drop::Drop(Gra *gra):
	Komenda(gra)
{
	nazwa="drop";
}


Drop::~Drop(void)
{
}

void Drop::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty()) 
	{
		playerMsg("Co chcesz wyrzuciæ?");
		return;
	}
	
	Gracz &gracz = gra->gracz;

	if (argumenty.argument1=="all")
	{
		if (gracz.przedmioty->pusta())
		{
			playerMsg("Przecie¿ nic nie masz biedaku.");
			return;
		}
		while (!gracz.przedmioty->pusta())
		{
			drop(gracz.przedmioty->znajdz(1));
		}
	}
	else
	{
		Item* aktualny;
		if (aktualny=gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1))
		{
			drop(aktualny);
		}
		else
		{
			playerMsg("Nie masz czegoœ takiego jak |0.", argumenty.argument1);
		}
	}
	
}

void Drop::manual()
{
	playerMsg("Synonimy:\n"
				"   drop(dro)\n\n"
				"U¿ycia:\n\n"
				"   drop <nazwa_przedmiotu> - upuszcza wskazany przedmiot na ziemiê.\n\n"
				"SprawdŸ równie¿:\n"
				"   take");
}

void Drop::drop(Item *przedmiot)
{
	gra->gracz.przedmioty->usun(przedmiot);
	gra->gracz.polozenie->przedmioty->dodaj(przedmiot);
	playerMsg("Upuszczasz |0.", przedmiot->nazwa);
}
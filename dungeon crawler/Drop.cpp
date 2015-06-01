#include "Drop.h"
#include "Gra.h"
#include "Item.h"
#include "Lokacja.h"

Drop::Drop(Gra *gra) :
Komenda(gra)
{
	nazwa = L"drop";
}


Drop::~Drop(void)
{
}

void Drop::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())
	{
		playerMsg(L"Co chcesz wyrzuciæ?");
		return;
	}

	Gracz &gracz = gra->gracz;

	if (argumenty.argument1 == L"all")
	{
		if (gracz.przedmioty->pusta())
		{
			playerMsg(L"Przecie¿ nic nie masz biedaku.");
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
		if (aktualny = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1))
		{
			drop(aktualny);
		}
		else
		{
			playerMsg(L"Nie masz czegoœ takiego jak |0.", argumenty.argument1);
		}
	}

}

void Drop::manual()
{
	playerMsg(L"Synonimy:\n"
		L"   drop(dro)\n\n"
		L"U¿ycia:\n\n"
		L"   drop <nazwa_przedmiotu> - upuszcza wskazany przedmiot na ziemiê.\n\n"
		L"SprawdŸ równie¿:\n"
		L"   take");
}

void Drop::drop(Item *przedmiot)
{
	gra->gracz.przedmioty->usun(przedmiot);
	gra->gracz.polozenie->przedmioty->dodaj(przedmiot);
	playerMsg(L"Upuszczasz |0.", przedmiot->nazwa);
}
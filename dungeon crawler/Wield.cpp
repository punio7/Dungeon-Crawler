#include "Wield.h"
#include "gra.h"
#include "item.h"
#include "Wear.h"
#include "Remove.h"

extern ListaKomend *listaKomend;

Wield::Wield(Gra *gra):
	Komenda(gra)
{
	nazwa = L"wield";
}


Wield::~Wield(void)
{
}

void Wield::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;

	if (argumenty.argument1.empty())
	{
		playerMsg(L"Co chcesz na³o¿yæ?");
		return;
	}

	Item* przedmiot = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);

	if (przedmiot==NULL)
	{
		playerMsg(L"Nie masz przy sobie czegoœ takiego jak |0.", argumenty.argument1);
		return;
	}

	if (!przedmiot->jestBronia())
	{
		playerMsg(L"|^|0 nie jest broni¹ w konwencjonalnym tego s³owa znaczeniu.", przedmiot->nazwa);
		return;
	}

	if (gracz.eq[SLOT_PREKA])		//jezeli jest w tym slocie juz jakis przedmiot
	{								//to go zdejmujemy
		dynamic_cast<Remove*>(listaKomend->komendy[COMM_REMOVE])->remove(SLOT_PREKA);

	}
	if (przedmiot->typ==ITEM_2HWEAPON && gracz.eq[SLOT_LREKA])	//je¿eli broñ jest dwurêczna
	{														//to automatycznie przestajemy u¿ywaæ przedmiotu z lewej reki
		dynamic_cast<Remove*>(listaKomend->komendy[COMM_REMOVE])->remove(SLOT_LREKA);

	}
	gracz.przedmioty->usun(przedmiot);
	gracz.eq[SLOT_PREKA]=przedmiot;
	playerMsg(L"Dobywasz |0.", przedmiot->nazwa);
	gracz.przelicz();
	dynamic_cast<Wear*>(listaKomend->komendy[COMM_WEAR])->sprawdzWymagania(przedmiot);
}

void Wield::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   wield(wi)\n\n"
			 L"U¿ycia:\n\n"
			 L"   wield <nazwa_przedmiotu> - rozkazuje postaci dobycie wskazanej broni. Musi siê ona znajdowaæ w inwentarzu gracza.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   wear, hold, remove");
}
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
		playerMsg(L"Co chcesz na�o�y�?");
		return;
	}

	Item* przedmiot = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);

	if (przedmiot==NULL)
	{
		playerMsg(L"Nie masz przy sobie czego� takiego jak |0.", argumenty.argument1);
		return;
	}

	if (!przedmiot->jestBronia())
	{
		playerMsg(L"|^|0 nie jest broni� w konwencjonalnym tego s�owa znaczeniu.", przedmiot->nazwa);
		return;
	}

	if (gracz.eq[SLOT_PREKA])		//jezeli jest w tym slocie juz jakis przedmiot
	{								//to go zdejmujemy
		dynamic_cast<Remove*>(listaKomend->komendy[COMM_REMOVE])->remove(SLOT_PREKA);

	}
	if (przedmiot->typ==ITEM_2HWEAPON && gracz.eq[SLOT_LREKA])	//je�eli bro� jest dwur�czna
	{														//to automatycznie przestajemy u�ywa� przedmiotu z lewej reki
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
			 L"U�ycia:\n\n"
			 L"   wield <nazwa_przedmiotu> - rozkazuje postaci dobycie wskazanej broni. Musi si� ona znajdowa� w inwentarzu gracza.\n\n"
			 L"Sprawd� r�wnie�:\n"
			 L"   wear, hold, remove");
}
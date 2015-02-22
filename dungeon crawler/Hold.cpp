#include "Hold.h"
#include "gra.h"
#include "item.h"
#include "Wear.h"
#include "Remove.h"

extern ListaKomend *listaKomend;

Hold::Hold(Gra *gra):
	Komenda(gra)
{
	nazwa="hold";
}


Hold::~Hold(void)
{
}

void Hold::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;
	if (argumenty.argument1.empty())
	{
		playerMsg("Co chcesz na³o¿yæ?");
		return;
	}

	Item* przedmiot = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);

	if (przedmiot==NULL)
	{
		playerMsg("Nie masz przy sobie czegoœ takiego jak |0.", argumenty.argument1);
		return;
	}

	if(!(przedmiot->jestBronia() || przedmiot->jestTarcza()))
	{
		playerMsg("|^|0 nie jest broni¹ ani tarcz¹.", przedmiot->nazwa);
		return;
	}

	if (gracz.eq[SLOT_LREKA])		//jezeli jest w tym slocie juz jakis przedmiot
	{								//to go zdejmujemy
		dynamic_cast<Remove*>(listaKomend->komendy[COMM_REMOVE])->remove(SLOT_LREKA);

	}
	gracz.przedmioty->usun(przedmiot);
	gracz.eq[SLOT_LREKA]=przedmiot;
	playerMsg("Chwytasz |0 w lew¹ rêkê.", przedmiot->nazwa);
	gracz.przelicz();
	dynamic_cast<Wear*>(listaKomend->komendy[COMM_WEAR])->sprawdzWymagania(przedmiot);
}

void Hold::manual()
{
	playerMsg("Synonimy:\n"
				"   hold(h)\n\n"
				"U¿ycia:\n\n"
				"   hold <nazwa_przedmiotu> - rozkazuje postaci gracza u¿ywaæ danego przedmiotu w lewej rêce. Mo¿e to byæ broñ, tarcza, lub coœ innego. Przedmiot musi siê znajdowaæ w inwentarzu gracza.\n\n"
				"SprawdŸ równie¿:\n"
				"   wield, wear, remove");
}
#include "Hold.h"
#include "gra.h"
#include "item.h"
#include "Wear.h"
#include "Remove.h"

extern ListaKomend *listaKomend;

Hold::Hold(Gra *gra):
	Komenda(gra)
{
	nazwa = L"hold";
}


Hold::~Hold(void)
{
}

void Hold::execute(ParseDTO argumenty)
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

	if(!(przedmiot->jestBronia() || przedmiot->jestTarcza()))
	{
		playerMsg(L"|^|0 nie jest broni� ani tarcz�.", przedmiot->nazwa);
		return;
	}

	if (gracz.eq[SLOT_LREKA])		//jezeli jest w tym slocie juz jakis przedmiot
	{								//to go zdejmujemy
		dynamic_cast<Remove*>(listaKomend->komendy[COMM_REMOVE])->remove(SLOT_LREKA);

	}
	gracz.przedmioty->usun(przedmiot);
	gracz.eq[SLOT_LREKA]=przedmiot;
	playerMsg(L"Chwytasz |0 w lew� r�k�.", przedmiot->nazwa);
	gracz.przelicz();
	dynamic_cast<Wear*>(listaKomend->komendy[COMM_WEAR])->sprawdzWymagania(przedmiot);
}

void Hold::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   hold(h)\n\n"
			 L"U�ycia:\n\n"
			 L"   hold <nazwa_przedmiotu> - rozkazuje postaci gracza u�ywa� danego przedmiotu w lewej r�ce. Mo�e to by� bro�, tarcza, lub co� innego. Przedmiot musi si� znajdowa� w inwentarzu gracza.\n\n"
			 L"Sprawd� r�wnie�:\n"
			 L"   wield, wear, remove");
}
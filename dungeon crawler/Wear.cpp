#include "Wear.h"
#include "Gra.h"
#include "Item.h"
#include "Remove.h"
#include "ListaKomend.h"

extern ListaKomend *listaKomend;

Wear::Wear(Gra *gra):
	Komenda(gra)
{
	nazwa = L"wear";
}


Wear::~Wear(void)
{
}

void Wear::execute(ParseDTO argumenty)
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

	if (!przedmiot->jestPancerzem())
	{
		playerMsg(L"|^|0 nie da siê w ¿aden sposób na³o¿yæ.", przedmiot->nazwa);
		return;
	}

	
	ItemSlot slot = przedmiot->getSlot();

	if (slot == SLOT_PIERSCIENR)	//jezeli prawy pierscien jest zajety a lewy wolny
	{								//to zakladamy go na lewym
		if (gracz.eq[SLOT_PIERSCIENR] && !gracz.eq[SLOT_PIERSCIENL])
			slot = SLOT_PIERSCIENL;
	}

	if (gracz.eq[slot])		//jezeli jest w tym slocie juz jakis przedmiot
	{						//to go zdejmujemy
		dynamic_cast<Remove*>(listaKomend->komendy[COMM_REMOVE])->remove(slot);
	}
	gracz.przedmioty->usun(przedmiot);
	gracz.eq[slot] = przedmiot;
	playerMsg(L"Nak³adasz |0.", przedmiot->nazwa);
	gracz.przelicz();
	sprawdzWymagania(przedmiot);
	
}

void Wear::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   wear(wea)\n\n"
			 L"U¿ycia:\n\n"
			 L"   wear <nazwa_przedmiotu> - rozkazuje postaci na³o¿enie wskazanego przedmiotu. Mo¿e to byæ pancerz, ubranie itp. Musi siê ono znajdowaæ w inwentarzu gracza.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   wield, hold, remove");
}

void Wear::sprawdzWymagania(Item *item)
{
	Gracz &gracz = gra->gracz;
	
	Staty staty = item->czytaj_staty();
	if (gracz.sil_calk < staty.sil)
	{
		playerMsg(L"Twoja si³a jest za ma³a aby sprawnie pos³ugiwaæ siê tym przedmiotem.");
	}
	if (gracz.zr_calk < staty.zr)
	{
		playerMsg(L"Twoja zrêcznoœæ jest za ma³a aby sprawnie pos³ugiwaæ siê tym przedmiotem.");
	}
	if (gracz.zw_calk < staty.zw)
	{
		playerMsg(L"Twoja zwinnoœæ jest za ma³a aby sprawnie pos³ugiwaæ siê tym przedmiotem.");
	}
	if (gracz.wyt_calk < staty.wyt)
	{
		playerMsg(L"Twoja wytrzyma³oœæ jest za ma³a aby sprawnie pos³ugiwaæ siê tym przedmiotem.");
	}
	if (gracz.zyw_calk < staty.zyw)
	{
		playerMsg(L"Twoja ¿ywotnoœæ jest za ma³a aby sprawnie pos³ugiwaæ siê tym przedmiotem.");
	}
}
#include "Wear.h"
#include "gra.h"
#include "item.h"
#include "Remove.h"

extern ListaKomend *listaKomend;

Wear::Wear(Gra *gra):
	Komenda(gra)
{
	nazwa="wear";
}


Wear::~Wear(void)
{
}

void Wear::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;
	
	if (argumenty.argument1.empty())
	{
		playerMsg("Co chcesz na�o�y�?");
		return;
	}

	Item* przedmiot = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);

	if (przedmiot==NULL)
	{
		playerMsg("Nie masz przy sobie czego� takiego jak |0.", argumenty.argument1);
		return;
	}

	if (!przedmiot->jestPancerzem())
	{
		playerMsg("|^|0 nie da si� w �aden spos�b na�o�y�.", przedmiot->nazwa);
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
	playerMsg("Nak�adasz |0.", przedmiot->nazwa);
	gracz.przelicz();
	sprawdzWymagania(przedmiot);
	
}

void Wear::manual()
{
	playerMsg("Synonimy:\n"
				"   wear(wea)\n\n"
				"U�ycia:\n\n"
				"   wear <nazwa_przedmiotu> - rozkazuje postaci na�o�enie wskazanego przedmiotu. Mo�e to by� pancerz, ubranie itp. Musi si� ono znajdowa� w inwentarzu gracza.\n\n"
				"Sprawd� r�wnie�:\n"
				"   wield, hold, remove");
}

void Wear::sprawdzWymagania(Item *item)
{
	Gracz &gracz = gra->gracz;
	
	Staty staty = item->czytaj_staty();
	if (gracz.sil_calk < staty.sil)
	{
		playerMsg("Twoja si�a jest za ma�a aby sprawnie pos�ugiwa� si� tym przedmiotem.");
	}
	if (gracz.zr_calk < staty.zr)
	{
		playerMsg("Twoja zr�czno�� jest za ma�a aby sprawnie pos�ugiwa� si� tym przedmiotem.");
	}
	if (gracz.zw_calk < staty.zw)
	{
		playerMsg("Twoja zwinno�� jest za ma�a aby sprawnie pos�ugiwa� si� tym przedmiotem.");
	}
	if (gracz.wyt_calk < staty.wyt)
	{
		playerMsg("Twoja wytrzyma�o�� jest za ma�a aby sprawnie pos�ugiwa� si� tym przedmiotem.");
	}
	if (gracz.zyw_calk < staty.zyw)
	{
		playerMsg("Twoja �ywotno�� jest za ma�a aby sprawnie pos�ugiwa� si� tym przedmiotem.");
	}
}
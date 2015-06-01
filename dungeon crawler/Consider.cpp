#include "Consider.h"
#include "Gra.h"
#include "Item.h"
#include "Lokacja.h"

Consider::Consider(Gra *gra):
	Komenda(gra)
{
	nazwa = L"consider";
}


Consider::~Consider(void)
{
}

void Consider::execute(ParseDTO argumenty)
{
	Postac *postac = NULL;
	Item *item = NULL;
	if ( (postac = gra->gracz.polozenie->postacie->znajdz(argumenty.argument1, argumenty.ktory1)) != NULL)
	{
		consider(postac);
		return;
	}
	else if ( (item = gra->gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1)) != NULL)
	{
		consider(item);
		return;
	}
	playerMsg(L"Niby z czym chcia³byœ siê porównaæ?");
}

void Consider::manual()
{
	playerMsg(L"Synonimy:\n"
				L"   consider(cons)\n\n"
				L"U¿ycia:\n\n"
				L"   consider <nazwa_przedmiotu> - porównuje wskazany przedmiot z wyekwipowanym przedmiotem tego samego typu. Porównywany przedmiot musi siê znajdowaæ w inwentarzu.\n\n"
				L"   consider <nazwa_postaci> - porównuje zdolnoœci bitewne gracza ze wskazan¹ postaci¹.\n\n"
				L"SprawdŸ równie¿:\n"
				L"   wear, wield, hold, remove, kill");
}

void Consider::consider(Item *porownywany)
{
	Item *aktualny = NULL;
	ItemSlot slot = porownywany->getSlot();
	if (slot == -1)
	{
		playerMsg(L"Mo¿esz porównywaæ tylko elementy ekwipunku.");
		return;
	}

	aktualny = gra->gracz.eq[slot];

	if (aktualny == NULL)
	{
		playerMsg(L"Lepszy |0 ni¿ powietrze.", porownywany->nazwa);
		return;
	}
	Item *lepszy = aktualny;
	Staty aktualnyS = aktualny->czytaj_staty();
	Staty porownywanyS = porownywany->czytaj_staty();

	if (aktualnyS.dmg != porownywanyS.dmg)
	{
		lepszy = (aktualnyS.dmg > porownywanyS.dmg ? aktualny : porownywany);
		playerMsg(L"|^|0 mo¿e wyrz¹dziæ przeciwnikowi wiêcej szkód.", lepszy->nazwa);
	}
	else 
	{
		playerMsg(L"Oba przedmioty mog¹ wyrz¹dziæ przeciwnikowi podobne szkody.");
	}

	if (aktualnyS.atak != porownywanyS.atak)
	{
		lepszy = (aktualnyS.atak > porownywanyS.atak ? aktualny : porownywany);
		playerMsg(L"|^|0 bardziej ci pomo¿e w wyprowadzaniu ciosów.", lepszy->nazwa);
	}
	else 
	{
		playerMsg(L"Oba przedmioty s¹ równie u¿yteczne przy wyprowadzaniu ciosów.");
	}

	if (aktualnyS.obrona != porownywanyS.obrona)
	{
		lepszy = (aktualnyS.obrona > porownywanyS.obrona ? aktualny : porownywany);
		playerMsg(L"|^|0 bardziej u³atwi ci obronê.", lepszy->nazwa);
	}
	else 
	{
		playerMsg(L"Oba przedmioty równie dobrze u³atwiaj¹ obronê.");
	}


	if (! aktualny->jestPancerzem() ) return;		//dalsze porownania dotycza tylko pancerzy


	if (aktualnyS.ochrona != porownywanyS.ochrona)
	{
		lepszy = (aktualnyS.ochrona > porownywanyS.ochrona ? aktualny : porownywany);
		playerMsg(L"|^|0 zapewnia dok³adniejsz¹ ochronê.", lepszy->nazwa);
	}
	else 
	{
		playerMsg(L"Oba pancerze zapewniaj¹ podobn¹ ochronê.");
	}

	if (aktualnyS.pancerz != porownywanyS.pancerz)
	{
		lepszy = (aktualnyS.pancerz > porownywanyS.pancerz ? aktualny : porownywany);
		playerMsg(L"|^|0 jest bardziej wytrzyma³y.", lepszy->nazwa);
	}
	else 
	{
		playerMsg(L"Oba pancerze s¹ równie wytrzyma³e.");
	}
}

void Consider::consider(Postac *przeciwnik)
{
	int poziom = gra->gracz.poziom;
	int roznica = przeciwnik->poziom - poziom;

	if (roznica > poziom*1.2)
	{
		playerMsg(L"|^|0 jest od ciebie znacznie potê¿niejszy.", przeciwnik->imie);
	}
	else if (roznica > 0)
	{
		playerMsg(L"|^|0 wygl¹da na godnego przeciwnika.", przeciwnik->imie);
	}
	else if (roznica > poziom*(-1.2))
	{
		playerMsg(L"|^|0 wygl¹da na ³atwego przeciwnika.", przeciwnik->imie);
	}
	else
	{
		playerMsg(L"|^|0 nie stanowi dla ciebie wyzwania.", przeciwnik->imie);
	}
	
	playerMsg(L"G³ówne cechy przeciwnika to: |G|0|W oraz |G|1|W.",
		przeciwnik->cechaTowstring(przeciwnik->najwyzszaCecha(0)), 
		przeciwnik->cechaTowstring(przeciwnik->najwyzszaCecha(1)) );
}
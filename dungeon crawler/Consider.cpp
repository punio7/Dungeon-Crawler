#include "Consider.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"

Consider::Consider(Gra *gra):
	Komenda(gra)
{
	nazwa="consider";
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
	playerMsg("Niby z czym chcia�by� si� por�wna�?");
}

void Consider::manual()
{
	playerMsg("Synonimy:\n"
				"   consider(cons)\n\n"
				"U�ycia:\n\n"
				"   consider <nazwa_przedmiotu> - por�wnuje wskazany przedmiot z wyekwipowanym przedmiotem tego samego typu. Por�wnywany przedmiot musi si� znajdowa� w inwentarzu.\n\n"
				"   consider <nazwa_postaci> - por�wnuje zdolno�ci bitewne gracza ze wskazan� postaci�.\n\n"
				"Sprawd� r�wnie�:\n"
				"   wear, wield, hold, remove, kill");
}

void Consider::consider(Item *porownywany)
{
	Item *aktualny = NULL;
	ItemSlot slot = porownywany->getSlot();
	if (slot == -1)
	{
		playerMsg("Mo�esz por�wnywa� tylko elementy ekwipunku.");
		return;
	}

	aktualny = gra->gracz.eq[slot];

	if (aktualny == NULL)
	{
		playerMsg("Lepszy |0 ni� powietrze.", porownywany->nazwa);
		return;
	}
	Item *lepszy = aktualny;
	Staty aktualnyS = aktualny->czytaj_staty();
	Staty porownywanyS = porownywany->czytaj_staty();

	if (aktualnyS.dmg != porownywanyS.dmg)
	{
		lepszy = (aktualnyS.dmg > porownywanyS.dmg ? aktualny : porownywany);
		playerMsg("|^|0 mo�e wyrz�dzi� przeciwnikowi wi�cej szk�d.", lepszy->nazwa);
	}
	else 
	{
		playerMsg("Oba przedmioty mog� wyrz�dzi� przeciwnikowi podobne szkody.");
	}

	if (aktualnyS.atak != porownywanyS.atak)
	{
		lepszy = (aktualnyS.atak > porownywanyS.atak ? aktualny : porownywany);
		playerMsg("|^|0 bardziej ci pomo�e w wyprowadzaniu cios�w.", lepszy->nazwa);
	}
	else 
	{
		playerMsg("Oba przedmioty s� r�wnie u�yteczne przy wyprowadzaniu cios�w.");
	}

	if (aktualnyS.obrona != porownywanyS.obrona)
	{
		lepszy = (aktualnyS.obrona > porownywanyS.obrona ? aktualny : porownywany);
		playerMsg("|^|0 bardziej u�atwi ci obron�.", lepszy->nazwa);
	}
	else 
	{
		playerMsg("Oba przedmioty r�wnie dobrze u�atwiaj� obron�.");
	}


	if (! aktualny->jestPancerzem() ) return;		//dalsze porownania dotycza tylko pancerzy


	if (aktualnyS.ochrona != porownywanyS.ochrona)
	{
		lepszy = (aktualnyS.ochrona > porownywanyS.ochrona ? aktualny : porownywany);
		playerMsg("|^|0 zapewnia dok�adniejsz� ochron�.", lepszy->nazwa);
	}
	else 
	{
		playerMsg("Oba pancerze zapewniaj� podobn� ochron�.");
	}

	if (aktualnyS.pancerz != porownywanyS.pancerz)
	{
		lepszy = (aktualnyS.pancerz > porownywanyS.pancerz ? aktualny : porownywany);
		playerMsg("|^|0 jest bardziej wytrzyma�y.", lepszy->nazwa);
	}
	else 
	{
		playerMsg("Oba pancerze s� r�wnie wytrzyma�e.");
	}
}

void Consider::consider(Postac *przeciwnik)
{
	int poziom = gra->gracz.poziom;
	int roznica = przeciwnik->poziom - poziom;

	if (roznica > poziom*1.2)
	{
		playerMsg("|^|0 jest od ciebie znacznie pot�niejszy.", przeciwnik->imie);
	}
	else if (roznica > 0)
	{
		playerMsg("|^|0 wygl�da na godnego przeciwnika.", przeciwnik->imie);
	}
	else if (roznica > poziom*(-1.2))
	{
		playerMsg("|^|0 wygl�da na �atwego przeciwnika.", przeciwnik->imie);
	}
	else
	{
		playerMsg("|^|0 nie stanowi dla ciebie wyzwania.", przeciwnik->imie);
	}
	
	playerMsg("G��wne cechy przeciwnika to: |G|0|W oraz |G|1|W.",
		przeciwnik->cechaToString(przeciwnik->najwyzszaCecha(0)), 
		przeciwnik->cechaToString(przeciwnik->najwyzszaCecha(1)) );
}
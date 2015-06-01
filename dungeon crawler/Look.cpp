#include "Look.h"
#include "Gra.h"
#include "Item.h"
#include "Lokacja.h"

Look::Look(Gra *gra) :
Komenda(gra)
{
	nazwa = L"look";
}


Look::~Look(void)
{
}

void Look::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;

	if (argumenty.argument1.empty())
		LookMiejsce(gracz.polozenie);	//nie podano argumenty- patrzymy wokol siebie
	else
	{
		Postac* postac;		//podano nazwe czegos, szukamy jej w liscie postaci
		if (postac = (gracz.polozenie->postacie)->znajdz(argumenty.argument1, argumenty.ktory1))
			LookPostac(postac);
		else
		{
			Item* przedmiot;
			if (przedmiot = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1))	//to nie byla postac szukamy przedmiotu w plecaku
			{
				LookPrzedmiot(przedmiot);
			}
			else
			{
				if (przedmiot = gracz.polozenie->przedmioty->znajdz(argumenty.argument1, argumenty.ktory1))	//nie ma przedmiotu w plecaku, szukamy wokol nas
				{
					LookPrzedmiot(przedmiot);
				}
				else
				{
					playerMsg(L"Tutaj nie ma czegoœ takiego jak |0.", argumenty.argument1);
				}
			}
		}
	}
}

void Look::manual()
{
	playerMsg(L"Synonimy:\n"
		L"   look(l)\n\n"
		L"U¿ycia:\n\n"
		L"   look - wyœwietla opis lokacji w której obecnie znajduje siê gracz.\n\n"
		L"   look <nazwa_przedmiotu> - wyœwietla opis wskazanego przedmiotu. Przedmiot mo¿e siê znajdowaæ w inwentarzu gracza lub w jego obecnej lokacji.\n\n"
		L"   look <nazwa_postaci> - wyœwietla opis wskazanej postaci. Postaæ musi siê znajdowaæ w lokacji gracza.\n\n"
		L"SprawdŸ równie¿:\n"
		L"   examine, scan");
}

void Look::LookMiejsce(Lokacja *polozenie)
{
	LookMiejsceOswietlone(polozenie);
}

void Look::LookMiejsceOswietlone(Lokacja *polozenie)
{
	playerMsg(polozenie->nazwa);
	wstring temp;	//bedzie zawieral spis wszystkich wyjsc

	if ((polozenie->zamek)[NORTH] > 0) temp += L"*";		//jezeli wyjscie jest zamkniete to na liscie wyjsc bedzie gwiazdka
	if ((polozenie->wyjscie)[NORTH] && (polozenie->zamek)[NORTH] != -1) temp += L"pó³noc ";	//je¿eli przejœcie do nik¹d nie prowadzi, b¹dŸ jest ukryte to nie bedzie go na liscie lokacji

	if ((polozenie->zamek)[SOUTH] > 0) temp += L"*";
	if ((polozenie->wyjscie)[SOUTH] && (polozenie->zamek)[SOUTH] != -1) temp += L"po³udnie ";

	if ((polozenie->zamek)[WEST] > 0) temp += L"*";
	if ((polozenie->wyjscie)[WEST] && (polozenie->zamek)[WEST] != -1) temp += L"zachód ";

	if ((polozenie->zamek)[EAST] > 0) temp += L"*";
	if ((polozenie->wyjscie)[EAST] && (polozenie->zamek)[EAST] != -1) temp += L"wschód ";

	if ((polozenie->zamek)[UP] > 0) temp += L"*";
	if ((polozenie->wyjscie)[UP] && (polozenie->zamek)[UP] != -1) temp += L"góra ";

	if ((polozenie->zamek)[DOWN] > 0) temp += L"*";
	if ((polozenie->wyjscie)[DOWN] && (polozenie->zamek)[DOWN] != -1) temp += L"dó³ ";

	playerMsg(L"|gWyjscia: [ |0]|W\n", temp);
	playerMsg(polozenie->opis);
	if (!(polozenie->postacie)->pusta())
	{
		playerMsg(L"\n|0", (polozenie->postacie)->wypisz());
	}
	if (!(polozenie->przedmioty)->pusta())
	{
		playerMsg(L"\n|0", polozenie->przedmioty->wypisz());
	}
}

void Look::LookMiejsceCiemno(Lokacja *polozenie)
{

}

void Look::LookPrzedmiot(Item *cel)
{
	playerMsg(cel->look());
}

void Look::LookPostac(Postac *cel)
{
	playerMsg(cel->opis);
	playerMsg(L"\n|0 jest |1.", cel->imie, cel->poziomZdrowia(1));
}
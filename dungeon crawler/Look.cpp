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
					playerMsg(L"Tutaj nie ma czego� takiego jak |0.", argumenty.argument1);
				}
			}
		}
	}
}

void Look::manual()
{
	playerMsg(L"Synonimy:\n"
		L"   look(l)\n\n"
		L"U�ycia:\n\n"
		L"   look - wy�wietla opis lokacji w kt�rej obecnie znajduje si� gracz.\n\n"
		L"   look <nazwa_przedmiotu> - wy�wietla opis wskazanego przedmiotu. Przedmiot mo�e si� znajdowa� w inwentarzu gracza lub w jego obecnej lokacji.\n\n"
		L"   look <nazwa_postaci> - wy�wietla opis wskazanej postaci. Posta� musi si� znajdowa� w lokacji gracza.\n\n"
		L"Sprawd� r�wnie�:\n"
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
	if ((polozenie->wyjscie)[NORTH] && (polozenie->zamek)[NORTH] != -1) temp += L"p�noc ";	//je�eli przej�cie do nik�d nie prowadzi, b�d� jest ukryte to nie bedzie go na liscie lokacji

	if ((polozenie->zamek)[SOUTH] > 0) temp += L"*";
	if ((polozenie->wyjscie)[SOUTH] && (polozenie->zamek)[SOUTH] != -1) temp += L"po�udnie ";

	if ((polozenie->zamek)[WEST] > 0) temp += L"*";
	if ((polozenie->wyjscie)[WEST] && (polozenie->zamek)[WEST] != -1) temp += L"zach�d ";

	if ((polozenie->zamek)[EAST] > 0) temp += L"*";
	if ((polozenie->wyjscie)[EAST] && (polozenie->zamek)[EAST] != -1) temp += L"wsch�d ";

	if ((polozenie->zamek)[UP] > 0) temp += L"*";
	if ((polozenie->wyjscie)[UP] && (polozenie->zamek)[UP] != -1) temp += L"g�ra ";

	if ((polozenie->zamek)[DOWN] > 0) temp += L"*";
	if ((polozenie->wyjscie)[DOWN] && (polozenie->zamek)[DOWN] != -1) temp += L"d� ";

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
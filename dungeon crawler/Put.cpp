#include "Put.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"

Put::Put(Gra *gra) :
Komenda(gra)
{
	nazwa = L"put";
}


Put::~Put(void)
{
}

void Put::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())
	{
		playerMsg(L"Co chcesz w³o¿yæ?");
		return;
	}
	if (argumenty.argument2.empty())
	{
		playerMsg(L"Gdzie chcia³byœ w³o¿yæ |0?", argumenty.argument1);
		return;
	}

	Gracz &gracz = gra->gracz;
	Item* przedmiot = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);	//szukamy tylko w inventarzu
	if (przedmiot == NULL)								//zalozmy iz jezeli chcemy cos wlozy to najpierw musimy to podniesc
	{
		if (argumenty.argument1 != L"all")
		{
			playerMsg(L"Nie posiadasz przy sobie ¿adnego |0.", argumenty.argument1);
			return;
		}
	}

	Item* pojemnik = gracz.przedmioty->znajdz(argumenty.argument2, argumenty.ktory2);
	if (pojemnik == NULL) pojemnik = (gracz.polozenie->przedmioty)->znajdz(argumenty.argument2, argumenty.ktory2);
	if (pojemnik == NULL)
	{
		playerMsg(L"Tutaj nie ma niczego takiego jak |0.", argumenty.argument1);
		return;
	}
	if (!pojemnik->jestPojemnikiem())
	{
		playerMsg(L"Dywagacje na temat czy |0 mo¿na w³o¿yæ do |1 pozostawmy filozofom.", przedmiot->nazwa, pojemnik->nazwa);
		return;
	}

	if (przedmiot == pojemnik)
	{
		playerMsg(L"Niestety obawiam siê i¿ |0 nie da siê w³o¿yæ do samego siebie.", przedmiot->nazwa);
		return;
	}

	if (pojemnik->numerZamka())	//je¿eli pojemnik jest zamkniêty zamkiem
	{
		playerMsg(L"Pojemnik jest zamkniêty.");
		return;
	}

	if (argumenty.argument1 == L"all")
	{
		putAll(pojemnik);
	}
	else
	{
		put(przedmiot, pojemnik);
	}
}

void Put::put(Item *przedmiot, Item* pojemnik)
{
	gra->gracz.przedmioty->usun(przedmiot);
	pojemnik->lista_dodaj(przedmiot);
	playerMsg(L"Wk³adasz |0 do |1.", przedmiot->nazwa, pojemnik->nazwa);
}

void Put::putAll(Item *pojemnik)
{
	ItemList* przedmioty = gra->gracz.przedmioty;

	int i = 1;
	for (Item* aktualny = przedmioty->znajdz(i); aktualny != NULL; aktualny = przedmioty->znajdz(i))
	{
		if (aktualny != pojemnik)
		{
			put(aktualny, pojemnik);
		}
		else
		{
			i++;
		}
	}
}

void Put::manual()
{
	playerMsg(L"Synonimy:\n"
		L"   put(p)\n\n"
		L"U¿ycia:\n\n"
		L"   put <nazwa_przedmiotu> <nazwa_pojemnika> - gracz spróbuje w³o¿yæ wskazany przedmiot do wskazanego pojemnika. Przedmiot musi siê znajdowaæ w inwentarzu gracza.\n\n"
		L"SprawdŸ równie¿:\n"
		L"   inventory, wear, wield, hold, remove");
}
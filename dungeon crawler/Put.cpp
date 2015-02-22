#include "Put.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"

Put::Put(Gra *gra):
	Komenda(gra)
{
	nazwa="put";
}


Put::~Put(void)
{
}

void Put::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())
	{
		playerMsg("Co chcesz w�o�y�?");
		return;
	}
	if (argumenty.argument2.empty())
	{
		playerMsg("Gdzie chcia�by� w�o�y� |0?", argumenty.argument1);
		return;
	}
	
	Gracz &gracz = gra->gracz;
	Item* przedmiot=gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);	//szukamy tylko w inventarzu
	if (przedmiot==NULL)								//zalozmy iz jezeli chcemy cos wlozy to najpierw musimy to podniesc
	{
		if (argumenty.argument1!="all")
		{
			playerMsg("Nie posiadasz przy sobie �adnego |0.", argumenty.argument1);
			return;
		}
	}

	Item* pojemnik=gracz.przedmioty->znajdz(argumenty.argument2, argumenty.ktory2);
	if (pojemnik==NULL) pojemnik=(gracz.polozenie->przedmioty)->znajdz(argumenty.argument2, argumenty.ktory2);
	if (pojemnik==NULL)
	{
		playerMsg("Tutaj nie ma niczego takiego jak |0.", argumenty.argument1);
		return;
	}
	if (!pojemnik->jestPojemnikiem())
	{
		playerMsg("Dywagacje na temat czy |0 mo�na w�o�y� do |1 pozostawmy filozofom.", przedmiot->nazwa, pojemnik->nazwa);
		return;
	}

	if (przedmiot==pojemnik)
	{
		playerMsg("Niestety obawiam si� i� |0 nie da si� w�o�y� do samego siebie.", przedmiot->nazwa);
		return;
	}

	if (pojemnik->numerZamka())	//je�eli pojemnik jest zamkni�ty zamkiem
	{
		playerMsg("Pojemnik jest zamkni�ty.");
		return;
	}
	
	if (argumenty.argument1=="all")
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
	playerMsg("Wk�adasz |0 do |1.", przedmiot->nazwa, pojemnik->nazwa);
}

void Put::putAll(Item *pojemnik)
{
	ItemList* przedmioty = gra->gracz.przedmioty;

	int i=1;
	for (Item* aktualny = przedmioty->znajdz(i); aktualny!=NULL; aktualny = przedmioty->znajdz(i))
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
	playerMsg("Synonimy:\n"
				"   put(p)\n\n"
				"U�ycia:\n\n"
				"   put <nazwa_przedmiotu> <nazwa_pojemnika> - gracz spr�buje w�o�y� wskazany przedmiot do wskazanego pojemnika. Przedmiot musi si� znajdowa� w inwentarzu gracza.\n\n"
				"Sprawd� r�wnie�:\n"
				"   inventory, wear, wield, hold, remove");
}
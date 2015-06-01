#include "Buy.h"
#include "Gra.h"
#include "Item.h"
#include "Lokacja.h"


Buy::Buy(Gra *gra):
	Komenda(gra)
{
	nazwa = L"buy";
}


Buy::~Buy(void)
{
}

void Buy::execute(ParseDTO argumenty)
{
	Postac *kupiec = znajdzKupca(argumenty.argument2, argumenty.ktory2);

	if (!kupiec)
		return;

	if (argumenty.argument1.empty())
	{
		playerMsg(L"Co chcia�by� kupi�?");
		return;
	}

	Item *przed = kupiec->sklepZnajdz(argumenty.argument1, argumenty.ktory1);
	if (przed == NULL) 
	{
		playerMsg(L"|^|0 nie sprzedaje takiego przedmiotu.", kupiec->imie);
		return;
	}
	Gracz &gracz = gra->gracz;
	int cena = przed->wartoscKupna();
	if (cena > gracz.zloto)
	{
		playerMsg(L"Aby kupi� |0 potrzenujesz |1 szt. z�.", przed->nazwa, intToStr(cena));
		return;
	}
	kupiec->sklepSprzedaj(przed, cena);
	gracz.zloto-=cena;
	gracz.przedmioty->dodaj(przed);

	playerMsg(L"Kupi�e� |0 za |1 szt. z�.", przed->nazwa, intToStr(cena));
}

void Buy::manual()
{
	playerMsg(	L"Synonimy:\n"
				L"   buy(b)\n\n"
				L"U�ycia:\n\n"
				L"   buy <nazwa_przedmiotu> - kupuje wskazany przedmiot od pierwszego znalezionego w danej lokacji kupca. Gracz musi posiada� wymagan� ilo�� z�ota, kupiec musi posiada� podany przedmiot w swoim sklepie, przedmiot zostaje dodany do inwentarza gracza.\n\n"
				L"   buy <nazwa_przedmiotu> <nazwa_kupca> - to co wy�ej tylko sprecyzowane kt�rego kupca dotyczy.\n\n"
				L"Sprawd� r�wnie�:\n"
				L"   list, offer, sell");
}

Postac* Buy::znajdzKupca(wstring kupiec, int ktory)
{
	Postac *postac = NULL;
	Lokacja *polozenie = gra->gracz.polozenie;

	if (kupiec.empty())	//jezeli gracz nie sprecyzowal kupca to szukamy pierwszego lepszego
	{
		postac = polozenie->postacie->znajdzKupiec();
	}
	else
	{
		postac = polozenie->postacie->znajdz(kupiec, ktory);
	}

	if (postac == NULL)
	{
		playerMsg(L"Nie ma tu nikogo, kto chcia�by z tob� handlowa�.");
		return NULL;
	}

	if ( !postac->jestKupcem() )
	{
		playerMsg(L"|^|0 nie sprzedaje ani nie kupuje �adnych przedmiot�w.", postac->imie);
		return NULL;
	}

	return postac;
}
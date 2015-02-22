#include "Buy.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"


Buy::Buy(Gra *gra):
	Komenda(gra)
{
	nazwa = "buy";
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
		playerMsg("Co chcia�by� kupi�?");
		return;
	}

	Item *przed = kupiec->sklepZnajdz(argumenty.argument1, argumenty.ktory1);
	if (przed == NULL) 
	{
		playerMsg("|^|0 nie sprzedaje takiego przedmiotu.", kupiec->imie);
		return;
	}
	Gracz &gracz = gra->gracz;
	int cena = przed->wartoscKupna();
	if (cena > gracz.zloto)
	{
		playerMsg("Aby kupi� |0 potrzenujesz |1 szt. z�.", przed->nazwa, intToStr(cena));
		return;
	}
	kupiec->sklepSprzedaj(przed, cena);
	gracz.zloto-=cena;
	gracz.przedmioty->dodaj(przed);

	playerMsg("Kupi�e� |0 za |1 szt. z�.", przed->nazwa, intToStr(cena));
}

void Buy::manual()
{
	playerMsg(	"Synonimy:\n"
				"   buy(b)\n\n"
				"U�ycia:\n\n"
				"   buy <nazwa_przedmiotu> - kupuje wskazany przedmiot od pierwszego znalezionego w danej lokacji kupca. Gracz musi posiada� wymagan� ilo�� z�ota, kupiec musi posiada� podany przedmiot w swoim sklepie, przedmiot zostaje dodany do inwentarza gracza.\n\n"
				"   buy <nazwa_przedmiotu> <nazwa_kupca> - to co wy�ej tylko sprecyzowane kt�rego kupca dotyczy.\n\n"
				"Sprawd� r�wnie�:\n"
				"   list, offer, sell");
}

Postac* Buy::znajdzKupca(string kupiec, int ktory)
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
		playerMsg("Nie ma tu nikogo, kto chcia�by z tob� handlowa�.");
		return NULL;
	}

	if ( !postac->jestKupcem() )
	{
		playerMsg("|^|0 nie sprzedaje ani nie kupuje �adnych przedmiot�w.", postac->imie);
		return NULL;
	}

	return postac;
}
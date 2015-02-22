#include "Offer.h"
#include "gra.h"
#include "item.h"
#include "Buy.h"

extern ListaKomend *listaKomend;

Offer::Offer(Gra *gra):
	Komenda(gra)
{
	nazwa="offer";
}


Offer::~Offer(void)
{
}

void Offer::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;

	if (argumenty.argument1.empty())
	{
		playerMsg("Co chcia³byœ zaoferowaæ na sprzeda¿?");
		return;
	}

	Item *przed = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);
	if (przed == NULL) 
	{
		playerMsg("Nie posiadasz takiego przedmiotu.");
		return;
	}
	
	Postac *kupiec = dynamic_cast<Buy*>(listaKomend->komendy[COMM_BUY])->znajdzKupca(argumenty.argument2, argumenty.ktory2);

	if (!kupiec)
		return;

	if (kupiec->zloto == 0)
	{
		playerMsg("|^|0 nie ma ju¿ z³ota na handel.", kupiec->imie);
		return;
	}

	int cena = przed->wartoscSprzedazy();
	if (cena == 0)
	{
		playerMsg("|^|0 nie jest zainteresowany kupnem |1.", kupiec->imie,przed->nazwa);
		return;
	}
	if (cena > kupiec->zloto)
		cena = kupiec->zloto;

	playerMsg("|^|0 kupi |1 za |2 szt. z³.", kupiec->imie, przed->nazwa, intToStr(cena));
}

void Offer::manual()
{
	playerMsg("Synonimy:\n"
				"   offer(of)\n\n"
				"U¿ycia:\n\n"
				"   offer <nazwa_przedmiotu> - sk³ada ofertê sprzeda¿y wskazanego przedmiotu pierwszemu kupcowi w lokacji gracza. Przedmiot musi siê znajdowaæ w inwentarzu gracza.\n\n"
				"SprawdŸ równie¿:\n"
				"   sell, buy, list");
}
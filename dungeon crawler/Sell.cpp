#include "Sell.h"
#include "gra.h"
#include "item.h"
#include "Buy.h"

extern ListaKomend *listaKomend;

Sell::Sell(Gra *gra):
	Komenda(gra)
{
	nazwa="sell";
}


Sell::~Sell(void)
{
}

void Sell::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;

	if (argumenty.argument1.empty())
	{
		playerMsg("Co chcia�by� zaoferowa� na sprzeda�?");
		return;
	}

	Item *przed = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);
	if (przed == NULL) 
	{
		playerMsg("Nie posiadasz takiego przedmiotu.");
		return;
	}
	
	Postac *kupiec = dynamic_cast<Buy*>(listaKomend->komendy[COMM_BUY])->znajdzKupca(argumenty.argument2, argumenty.ktory2);

	if (kupiec->zloto == 0)
	{
		playerMsg("|^|0 nie ma ju� z�ota na handel.", kupiec->imie);
		return;
	}

	int cena = przed->wartoscSprzedazy();
	if (cena == 0)
	{
		playerMsg("|^|0 nie jest zainteresowany kupnem |1.", kupiec->imie,przed->nazwa);
		return;
	}

	if (kupiec->zloto < cena) cena = kupiec->zloto;
	kupiec->sklepKup(przed, cena);
	gracz.przedmioty->usun(przed);
	gracz.zloto += cena;
	cout<<"Sprzedajesz "<<przed->nazwa<<" za "<<cena<<" szt. z�."<<endl;
}

void Sell::manual()
{
	playerMsg(	"Synonimy:\n"
				"   sell(se)\n\n"
				"U�ycia:\n\n"
				"   sell <nazwa_przedmiotu> - sprzedaje podany przedmiot pierwszemu kupcowi w lokacji. Gracz musi posiada� dany przedmiot w inwentarzu, kupiec musi mie� jakiekolwiek z�oto. Je�eli nie stac go na zap�acenie pe�nej warto�ci to zap�aci tyle ile mo�e.\n\n"
				"   sell <nazwa_przedmiotu> <nazwa_kupca> - to co wy�ej tylko sprecyzowane kt�rego kupca dotyczy.\n\n"
				"Sprawd� r�wnie�:\n"
				"   list, offer, buy");
}
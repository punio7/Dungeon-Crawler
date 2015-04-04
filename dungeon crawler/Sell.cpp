#include "Sell.h"
#include "gra.h"
#include "item.h"
#include "Buy.h"

extern ListaKomend *listaKomend;

Sell::Sell(Gra *gra):
	Komenda(gra)
{
	nazwa = L"sell";
}


Sell::~Sell(void)
{
}

void Sell::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;

	if (argumenty.argument1.empty())
	{
		playerMsg(L"Co chcia³byœ zaoferowaæ na sprzeda¿?");
		return;
	}

	Item *przed = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);
	if (przed == NULL) 
	{
		playerMsg(L"Nie posiadasz takiego przedmiotu.");
		return;
	}
	
	Postac *kupiec = dynamic_cast<Buy*>(listaKomend->komendy[COMM_BUY])->znajdzKupca(argumenty.argument2, argumenty.ktory2);

	if (kupiec->zloto == 0)
	{
		playerMsg(L"|^|0 nie ma ju¿ z³ota na handel.", kupiec->imie);
		return;
	}

	int cena = przed->wartoscSprzedazy();
	if (cena == 0)
	{
		playerMsg(L"|^|0 nie jest zainteresowany kupnem |1.", kupiec->imie,przed->nazwa);
		return;
	}

	if (kupiec->zloto < cena) cena = kupiec->zloto;
	kupiec->sklepKup(przed, cena);
	gracz.przedmioty->usun(przed);
	gracz.zloto += cena;
	wcout<<"Sprzedajesz "<<przed->nazwa<<" za "<<cena<<" szt. z³."<<endl;
}

void Sell::manual()
{
	playerMsg( L"Synonimy:\n"
			 L"   sell(se)\n\n"
			 L"U¿ycia:\n\n"
			 L"   sell <nazwa_przedmiotu> - sprzedaje podany przedmiot pierwszemu kupcowi w lokacji. Gracz musi posiadaæ dany przedmiot w inwentarzu, kupiec musi mieæ jakiekolwiek z³oto. Je¿eli nie stac go na zap³acenie pe³nej wartoœci to zap³aci tyle ile mo¿e.\n\n"
			 L"   sell <nazwa_przedmiotu> <nazwa_kupca> - to co wy¿ej tylko sprecyzowane którego kupca dotyczy.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   list, offer, buy");
}
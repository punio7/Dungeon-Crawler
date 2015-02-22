#include "List.h"
#include "gra.h"
#include "Buy.h"

extern ListaKomend *listaKomend;

List::List(Gra *gra):
	Komenda(gra)
{
	nazwa="list";
}


List::~List(void)
{
}

void List::execute(ParseDTO argumenty)
{
	Postac *kupiec = dynamic_cast<Buy*>(listaKomend->komendy[COMM_BUY])->znajdzKupca(argumenty.argument1, argumenty.ktory1);

	if (!kupiec)
		return;

	playerMsg(kupiec->list());
}

void List::manual()
{
	playerMsg("Synonimy:\n"
				"   list(li)\n\n"
				"U¿ycia:\n\n"
				"   list - wyœwietla asortyment oraz cennik pierwszego kupca w lokacji gracza.\n\n"
				"   list <nazwa_postaci> - to co wy¿ej tylko sprecyzowane którego kupca dotyczy.\n\n"
				"SprawdŸ równie¿:\n"
				"   buy, sell, offer");
}
#include "List.h"
#include "Gra.h"
#include "Buy.h"
#include "ListaKomend.h"

extern ListaKomend *listaKomend;

List::List(Gra *gra):
	Komenda(gra)
{
	nazwa = L"list";
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
	playerMsg(L"Synonimy:\n"
			 L"   list(li)\n\n"
			 L"U¿ycia:\n\n"
			 L"   list - wyœwietla asortyment oraz cennik pierwszego kupca w lokacji gracza.\n\n"
			 L"   list <nazwa_postaci> - to co wy¿ej tylko sprecyzowane którego kupca dotyczy.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   buy, sell, offer");
}
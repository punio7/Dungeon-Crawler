#include "North.h"
#include "gra.h"
#include "Go.h"

extern ListaKomend *listaKomend;

North::North(Gra *gra):
	Komenda(gra)
{
	nazwa = L"north";
}


North::~North(void)
{
}

void North::execute(ParseDTO argumenty)
{
	//listaKomend->go->GoKierunek(NORTH);
	dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->GoKierunek(NORTH);
}

void North::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   north(n)\n\n"
			 L"U¿ycia:\n\n"
			 L"   north - przemieszcza gracza na pó³noc.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   south, west, east, up, down");
}
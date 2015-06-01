#include "South.h"
#include "Gra.h"
#include "Go.h"
#include "ListaKomend.h"

extern ListaKomend *listaKomend;

South::South(Gra *gra):
	Komenda(gra)
{
	nazwa = L"south";
}


South::~South(void)
{
}

void South::execute(ParseDTO argumenty)
{
	//listaKomend->go->GoKierunek(SOUTH);
	dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->GoKierunek(SOUTH);
}

void South::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   south(s)\n\n"
			 L"U¿ycia:\n\n"
			 L"   south - przemieszcza gracza na po³udnie.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   north, west, east, up, down");
}
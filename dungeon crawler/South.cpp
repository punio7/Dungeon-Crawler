#include "South.h"
#include "gra.h"
#include "Go.h"
extern ListaKomend *listaKomend;

South::South(Gra *gra):
	Komenda(gra)
{
	nazwa="south";
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
	playerMsg("Synonimy:\n"
				"   south(s)\n\n"
				"U¿ycia:\n\n"
				"   south - przemieszcza gracza na po³udnie.\n\n"
				"SprawdŸ równie¿:\n"
				"   north, west, east, up, down");
}
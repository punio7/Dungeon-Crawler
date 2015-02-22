#include "North.h"
#include "gra.h"
#include "Go.h"

extern ListaKomend *listaKomend;

North::North(Gra *gra):
	Komenda(gra)
{
	nazwa="north";
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
	playerMsg("Synonimy:\n"
				"   north(n)\n\n"
				"U¿ycia:\n\n"
				"   north - przemieszcza gracza na pó³noc.\n\n"
				"SprawdŸ równie¿:\n"
				"   south, west, east, up, down");
}
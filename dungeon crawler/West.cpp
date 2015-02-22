#include "West.h"
#include "gra.h"
#include "Go.h"
extern ListaKomend *listaKomend;

West::West(Gra *gra):
	Komenda(gra)
{
	nazwa="west";
}


West::~West(void)
{
}

void West::execute(ParseDTO argumenty)
{
	dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->GoKierunek(WEST);
}

void West::manual()
{
	playerMsg("Synonimy:\n"
				"   west(w)\n\n"
				"U¿ycia:\n\n"
				"   south - przemieszcza gracza na zachód.\n\n"
				"SprawdŸ równie¿:\n"
				"   north, south, east, up, down");
}
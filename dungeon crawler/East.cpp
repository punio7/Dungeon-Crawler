#include "East.h"
#include "gra.h"
#include "Go.h"
extern ListaKomend *listaKomend;

East::East(Gra *gra):
	Komenda(gra)
{
	nazwa="east";
}


East::~East(void)
{
}

void East::execute(ParseDTO argumenty)
{
	dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->GoKierunek(EAST);
}

void East::manual()
{
	playerMsg("Synonimy:\n"
				"   east(e)\n\n"
				"U¿ycia:\n\n"
				"   east - przemieszcza gracza na wschód.\n\n"
				"SprawdŸ równie¿:\n"
				"   north, south, west, up, down");
}
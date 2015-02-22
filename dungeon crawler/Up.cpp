#include "Up.h"
#include "gra.h"
#include "Go.h"

extern ListaKomend *listaKomend;

Up::Up(Gra *gra):
	Komenda(gra)
{
	nazwa="up";
}


Up::~Up(void)
{
}

void Up::execute(ParseDTO argumenty)
{
	dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->GoKierunek(UP);
}

void Up::manual()
{
	playerMsg("Synonimy:\n"
				"   up(u)\n\n"
				"U¿ycia:\n\n"
				"   up - przemieszcza gracza w górê pod drabinie, schodach itp.\n\n"
				"SprawdŸ równie¿:\n"
				"   north, south, west, east, down");
}
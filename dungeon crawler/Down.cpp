#include "Down.h"
#include "gra.h"
#include "Go.h"

extern ListaKomend *listaKomend;

Down::Down(Gra *gra):
	Komenda(gra)
{
	nazwa="down";
}


Down::~Down(void)
{
}

void Down::execute(ParseDTO argumenty)
{
	dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->GoKierunek(DOWN);
}

void Down::manual()
{
	playerMsg("Synonimy:\n"
				"   down(d)\n\n"
				"U�ycia:\n\n"
				"   down - przemieszcza gracza w d� drabiny/schod�w itp.\n\n"
				"Sprawd� r�wnie�:\n"
				"   north, south, east, west, up");
}
#include "Down.h"
#include "Gra.h"
#include "Go.h"
#include "ListaKomend.h"

extern ListaKomend *listaKomend;

Down::Down(Gra *gra):
	Komenda(gra)
{
	nazwa = L"down";
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
	playerMsg(L"Synonimy:\n"
				L"   down(d)\n\n"
				L"U�ycia:\n\n"
				L"   down - przemieszcza gracza w d� drabiny/schod�w itp.\n\n"
				L"Sprawd� r�wnie�:\n"
				L"   north, south, east, west, up");
}
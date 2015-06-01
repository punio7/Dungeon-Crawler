#include "Up.h"
#include "Gra.h"
#include "Go.h"
#include "ListaKomend.h"

extern ListaKomend *listaKomend;

Up::Up(Gra *gra):
	Komenda(gra)
{
	nazwa = L"up";
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
	playerMsg(L"Synonimy:\n"
			 L"   up(u)\n\n"
			 L"U¿ycia:\n\n"
			 L"   up - przemieszcza gracza w górê pod drabinie, schodach itp.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   north, south, west, east, down");
}
#include "East.h"
#include "Gra.h"
#include "Go.h"
#include "ListaKomend.h"

extern ListaKomend *listaKomend;

East::East(Gra *gra):
	Komenda(gra)
{
	nazwa = L"east";
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
	playerMsg(L"Synonimy:\n"
			 L"   east(e)\n\n"
			 L"U¿ycia:\n\n"
			 L"   east - przemieszcza gracza na wschód.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   north, south, west, up, down");
}
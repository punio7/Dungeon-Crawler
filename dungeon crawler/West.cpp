#include "West.h"
#include "Gra.h"
#include "Go.h"
#include "ListaKomend.h"

extern ListaKomend *listaKomend;

West::West(Gra *gra):
	Komenda(gra)
{
	nazwa = L"west";
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
	playerMsg(L"Synonimy:\n"
			 L"   west(w)\n\n"
			 L"U¿ycia:\n\n"
			 L"   south - przemieszcza gracza na zachód.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   north, south, east, up, down");
}
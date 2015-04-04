#include "Quit.h"
#include "gra.h"


Quit::Quit(Gra *gra):
	Komenda(gra)
{
	nazwa = L"quit";
}


Quit::~Quit(void)
{
}

void Quit::execute(ParseDTO argumenty)
{
	playerMsg(L"I tak wrócisz.");
	gra->stan=STAN_QUIT;
}

void Quit::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   quit(q)\n\n"
			 L"U¿ycia:\n\n"
			 L"   quit - koñczy grê.\n");
}
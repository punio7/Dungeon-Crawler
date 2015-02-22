#include "Quit.h"
#include "gra.h"


Quit::Quit(Gra *gra):
	Komenda(gra)
{
	nazwa="quit";
}


Quit::~Quit(void)
{
}

void Quit::execute(ParseDTO argumenty)
{
	playerMsg("I tak wrócisz.");
	gra->stan=STAN_QUIT;
}

void Quit::manual()
{
	playerMsg("Synonimy:\n"
				"   quit(q)\n\n"
				"U¿ycia:\n\n"
				"   quit - koñczy grê.\n");
}
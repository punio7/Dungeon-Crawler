#include "Komenda.h"
#include "playerMsg.h"


Komenda::Komenda(Gra *gra)
{
	this->gra = gra;
}


Komenda::~Komenda(void)
{
}

void Komenda::execute(ParseDTO argumenty)
{
	playerMsg("Chyba ty.");
}


void Komenda::manual()
{
	playerMsg("Brak pomocy na dany temat.");
}

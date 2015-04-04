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
	playerMsg(L"Chyba ty.");
}


void Komenda::manual()
{
	playerMsg(L"Brak pomocy na dany temat.");
}

#include "KomendaTemplate.h"
#include "Gra.h"


KomendaTemplate::KomendaTemplate(Gra *gra):
	Komenda(gra)
{
	nazwa = L"";	//TODO zmienic na nazwe komendy
}


KomendaTemplate::~KomendaTemplate(void)
{
}

void KomendaTemplate::execute(ParseDTO argumenty)
{

}

void KomendaTemplate::manual()
{
	Komenda::manual();	//TODO wpisac manual dla danej komendy
}
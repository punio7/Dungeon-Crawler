#include "Cheat.h"
#include "gra.h"
#include "Look.h"
#include "item.h"

Cheat::Cheat(Gra *gra):
	Komenda(gra)
{
	nazwa = "cheat";
}


Cheat::~Cheat(void)
{
}

void Cheat::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;
	playerMsg("arg2: |0 ktory2: |1", argumenty.argument2, intToStr(argumenty.ktory2));

	if (argumenty.argument1 == "tp")
	{
		if (argumenty.argument2.empty())
			return;
		gracz.polozenie=gra->getLokacja(atoi(argumenty.argument2.c_str()));
		gracz.poprzedniePolozenie = KIERUNEK_NIEPOPRAWNY;
		if (gra->zdarzeniaGlobalnePrzySpotkaniu())	//jezeli zdarzenie zwroci true to przerywamy reszte
			return;
		dynamic_cast<Look*>(listaKomend->komendy[COMM_LOOK])->LookMiejsce(gracz.polozenie);
		gra->zdarzeniaPrzySpotkaniu();
		return;
	}

	if (argumenty.argument1 == "item")
	{
		if (argumenty.argument2.empty())
			return;
		gracz.przedmioty->dodaj(gra->create_item(atoi(argumenty.argument2.c_str())));
	}
}

void Cheat::manual()
{
	playerMsg("Synonimy:\n"
				"   cheat(ch)\n\n"
				"U¿ycia:\n\n"
				"   cheat tp <numer_pokoju> - teleportuje do pokoju o danym numerze\n\n"
				"   cheat item <numer_przedmiotu> - tworzy przedmiot o podanym numerze");
}
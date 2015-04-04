#include "Cheat.h"
#include "gra.h"
#include "Look.h"
#include "item.h"

Cheat::Cheat(Gra *gra):
	Komenda(gra)
{
	nazwa = L"cheat";
}


Cheat::~Cheat(void)
{
}

void Cheat::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;
	playerMsg(L"arg2: |0 ktory2: |1", argumenty.argument2, intToStr(argumenty.ktory2));

	if (argumenty.argument1 == L"tp")
	{
		if (argumenty.argument2.empty())
			return;
		gracz.polozenie=gra->getLokacja(stoi(argumenty.argument2));
		gracz.poprzedniePolozenie = KIERUNEK_NIEPOPRAWNY;
		if (gra->zdarzeniaGlobalnePrzySpotkaniu())	//jezeli zdarzenie zwroci true to przerywamy reszte
			return;
		dynamic_cast<Look*>(listaKomend->komendy[COMM_LOOK])->LookMiejsce(gracz.polozenie);
		gra->zdarzeniaPrzySpotkaniu();
		return;
	}

	if (argumenty.argument1 == L"item")
	{
		if (argumenty.argument2.empty())
			return;
		gracz.przedmioty->dodaj(gra->create_item(stoi(argumenty.argument2)));
	}
}

void Cheat::manual()
{
	playerMsg(L"Synonimy:\n"
				L"   cheat(ch)\n\n"
				L"U¿ycia:\n\n"
				L"   cheat tp <numer_pokoju> - teleportuje do pokoju o danym numerze\n\n"
				L"   cheat item <numer_przedmiotu> - tworzy przedmiot o podanym numerze");
}
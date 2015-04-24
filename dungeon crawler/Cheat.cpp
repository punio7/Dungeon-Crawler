#include "Cheat.h"
#include "gra.h"
#include "Look.h"
#include "item.h"
#include "Quest.h"
#include "zdarzeniaGlobalne.h"

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
		return;
	}

	if (argumenty.argument1 == L"zd")
	{
		if (argumenty.argument2.empty())
			return;
		gra->zdarzenieGlobalne(stoi(argumenty.argument2));
		return;
	}

	if (argumenty.argument1 == L"quest")
	{
		if (argumenty.argument2.empty())
			return;
		auto pozycja = argumenty.argument2.find(':');
		if (pozycja == -1)
		{
			return;
		}
		wstring numerQuestaS = argumenty.argument2.substr(0, pozycja);
		wstring numerFazyS = argumenty.argument2.substr(pozycja + 1);
		int numerQuesta = stoi(numerQuestaS);
		int numerFazy = stoi(numerFazyS);

		if (numerQuesta >= gra->questy.size())
		{
			playerMsg(L"Niepoprawny numer questa");
			return;
		}
		auto quest = gra->questy[numerQuesta];
		if (numerFazy >= quest->listaFaz.size())
		{
			playerMsg(L"Niepoprawny numer fazy dla danego questa");
			return;
		}

		auto faza = quest->listaFaz[numerFazy];
		if (faza->wymRozmowa)
		{
			quest->spelnijRozmowa(numerFazy);
		}
		if (faza->wymSpecjalny)
		{
			quest->spelnijSpecjalny(numerFazy);
		}
		while (faza->wymPotwor)
		{
			quest->spelnijPotwor(numerFazy);
		}
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
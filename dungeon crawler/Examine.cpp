#include "Examine.h"
#include "Gra.h"
#include "Item.h"
#include "Lokacja.h"
#include "Scan.h"
#include "Score.h"
#include "Take.h"
#include "ListaKomend.h"

extern ListaKomend *listaKomend;

Examine::Examine(Gra *gra):
	Komenda(gra)
{
	nazwa = L"examine";
}


Examine::~Examine(void)
{
}

void Examine::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())
	{
		dynamic_cast<Scan*>(listaKomend->komendy[COMM_SCAN])->scan();
		return;
	}

	Postac* aktualny;
	Gracz &gracz= gra->gracz;
	if (aktualny = (gracz.polozenie->postacie)->znajdz(argumenty.argument1, argumenty.ktory1) )
	{
		playerMsg(L"|^|0 wygl¹da ca³kiem normalnie.", aktualny->imie);
		dynamic_cast<Score*>(listaKomend->komendy[COMM_SCORE])->wypiszStaty(aktualny);
		playerMsg(aktualny->wypiszEQ());
	}
	else
	{
		Item* aktualny;
		if (aktualny=gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1))	//najpierw przeszukujemy inv
		{
			playerMsg(aktualny->examine());
			if (!aktualny->numerZamka())
			{
				dynamic_cast<Take*>(listaKomend->komendy[COMM_TAKE])->zabierzZloto(aktualny);
			}
		}
		else
		{
			if (aktualny=(gracz.polozenie->przedmioty)->znajdz(argumenty.argument1, argumenty.ktory1))	//potem otoczenie
			{
				playerMsg(aktualny->examine());
				if (!aktualny->numerZamka())
				{
					dynamic_cast<Take*>(listaKomend->komendy[COMM_TAKE])->zabierzZloto(aktualny);
				}
			}
			else
			{
				playerMsg(L"Tutaj nie ma czegoœ takiego jak |0.", argumenty.argument1);
			}
		}
	}
}

void Examine::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   examine(ex)\n\n"
			 L"U¿ycia:\n\n"
			 L"   examine - dzia³a tak samo jak scan.\n\n"
			 L"   examine <nazwa_przedmiotu> - wyœwietla opis wskazanego przedmiotu, oraz jego zawartoœæ w przypadku pojemników. Przedmiot mo¿e siê znajdowaæ w inwentarzu gracza lub w jego obecnej lokacji.\n\n"
			 L"   examine <nazwa_postaci> - wyœwietla opis oraz wyposa¿enie wskazanej postaci. Postaæ musi znajdowaæ siê w lokacji gracza.\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   look, scan, take, put");
}
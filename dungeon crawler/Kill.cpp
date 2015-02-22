#include "Kill.h"
#include <Windows.h>
#include "Walka.h"
#include "gra.h"
#include "item.h"
#include "Quest.h"
#include "ListaItemow.h"
#include "Lokacja.h"
#include "Take.h"

extern ListaKomend *listaKomend;

Kill::Kill(Gra *gra) :
Komenda(gra)
{
	nazwa = "kill";
}


Kill::~Kill(void)
{
}

void Kill::execute(ParseDTO argumenty)
{
	if (!gra->gracz.jestUzbrojony())
	{
		playerMsg("Znajd� sobie najpierw jak�� bro�.");
		return;
	}
	Postac* wrog = ((gra->gracz.polozenie)->postacie)->znajdz(argumenty.argument1, argumenty.ktory1);

	if (!wrog)
	{
		playerMsg("Nie ma tu �adnego |0 do zabicia.", argumenty.argument1);
		return;
	}

	rozpocznijWalke(wrog);
}

void Kill::manual()
{
	playerMsg("Synonimy:\n"
		"   kill(k)\n\n"
		"U�ycia:\n\n"
		"   kill <nazwa_postaci> - rozpoczyna walk� ze wskazan� postaci�. Posta� musi znajdowa� si� w loakcji gracza, gracz musi dzier�y� jak�� bro�.\n\n"
		"Sprawd� r�wnie�:\n"
		"   consider, examine");
}

void Kill::rozpocznijWalke(Postac *wrog)
{
	Gracz &gracz = gra->gracz;

	if (!gracz.jestUzbrojony())
	{
		playerMsg("Nie masz si� czym broni�! Panikujesz! |^|0 wykorzystuje to i zabija ci� jednym ciosem.", wrog->imie);
		playerMsg("Nie �yjesz! A to peszek.");
		gra->zakonczGre();
		return;
	}

	Walka walka(&gracz, wrog);

	while (!walka.koniecWalki())
	{
		walka.kolejnaTura();
		if (!walka.koniecWalki()) 
			Sleep(1500);
	}

	int wynik = walka.wynikWalki();
	gracz.usunStatusyBitewne();
	wrog->usunStatusyBitewne();

	switch (wynik)
	{
	case 1:
		playerMsg("Wygrywasz walk�!");

		if (wrog->dawaneDoswiadczenie > 0)
		{
			if (DEBUG_WALKA)
				playerMsg("|YZdobywasz |0 pkt. do�wiadczenia.", intToStr(wrog->poziom));
			gracz.dodajEXP(wrog->dawaneDoswiadczenie);
		}
		else
		{
			playerMsg("Niczego si� nie nauczy�e�.");
		}
		zabijPostac(wrog, gracz.polozenie);
		return;
	case -1:
		playerMsg("Nie �yjesz! A to peszek.");
		gra->zakonczGre();
		return;
	default:
		return;
	}
}

void Kill::zabijPostac(Postac *postac, Lokacja *Lokacja)
{
	if (!(postac && Lokacja)) return;	//je�eli kt�ry� ze wska�nik�w to null

	Gracz &gracz = gra->gracz;

	Item* temp = gra->create_item(ListaItemow::Pojemniki::Zwloki, ITEM_CONTAINER,
		postac->rasa->nazwaZwlok,
		"Zw�oki le�� tu i gnij�.",
		"le�� i gnij�",
		0, 0, 0, 0, 0, 0, 0, 0);

	ItemList* przedmioty = postac->przedmioty;
	postac->deequipALL();
	while (!przedmioty->pusta())
	{
		temp->lista_dodaj(przedmioty->znajdz(1));
		przedmioty->usunPierwszy();
	}

	(Lokacja->przedmioty)->dodaj(temp);
	(Lokacja->postacie)->usun(postac);

	temp->dodajZloto(postac->zloto);

	if (gracz.polozenie == Lokacja)
		dynamic_cast<Take*>(listaKomend->komendy[COMM_TAKE])->zabierzZloto(temp);


	if (postac->quest)
		gra->questy[postac->quest]->spelnijPotwor(postac->questFaza);

	delete postac;
}
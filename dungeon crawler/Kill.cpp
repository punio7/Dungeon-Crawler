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
	nazwa = L"kill";
}


Kill::~Kill(void)
{
}

void Kill::execute(ParseDTO argumenty)
{
	if (!gra->gracz.jestUzbrojony())
	{
		playerMsg(L"Znajd� sobie najpierw jak�� bro�.");
		return;
	}
	Postac* wrog = ((gra->gracz.polozenie)->postacie)->znajdz(argumenty.argument1, argumenty.ktory1);

	if (!wrog)
	{
		playerMsg(L"Nie ma tu �adnego |0 do zabicia.", argumenty.argument1);
		return;
	}

	rozpocznijWalke(wrog);
}

void Kill::manual()
{
	playerMsg(L"Synonimy:\n"
	 L"   kill(k)\n\n"
	 L"U�ycia:\n\n"
	 L"   kill <nazwa_postaci> - rozpoczyna walk� ze wskazan� postaci�. Posta� musi znajdowa� si� w loakcji gracza, gracz musi dzier�y� jak�� bro�.\n\n"
	 L"Sprawd� r�wnie�:\n"
	 L"   consider, examine");
}

void Kill::rozpocznijWalke(Postac *wrog)
{
	Gracz &gracz = gra->gracz;

	if (!gracz.jestUzbrojony())
	{
		playerMsg(L"Nie masz si� czym broni�! Panikujesz! |^|0 wykorzystuje to i zabija ci� jednym ciosem.", wrog->imie);
		playerMsg(L"Nie �yjesz! A to peszek.");
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
		playerMsg(L"Wygrywasz walk�!");

		if (wrog->dawaneDoswiadczenie > 0)
		{
			gracz.dodajEXP(wrog->dawaneDoswiadczenie);
		}
		else
		{
			playerMsg(L"Niczego si� nie nauczy�e�.");
		}
		zabijPostac(wrog, gracz.polozenie);
		return;
	case -1:
		playerMsg(L"Nie �yjesz! A to peszek.");
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
	 L"Zw�oki le�� tu i gnij�.",
	 L"le�� i gnij�",
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
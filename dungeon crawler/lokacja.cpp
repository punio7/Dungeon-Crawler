#include "Lokacja.h"
#include "midi.h"
#include "postac.h"
#include "item.h"

KierunekSwiata kierunekPrzeciwny(KierunekSwiata kierunek)
{
	switch (kierunek)
	{
	case NORTH:
		return SOUTH;
	case SOUTH:
		return NORTH;
	case EAST:
		return WEST;
	case WEST:
		return EAST;
	case UP:
		return DOWN;
	case DOWN:
		return UP;
	default:
		return KIERUNEK_NIEPOPRAWNY;
	}
}

ListaLokacji::ListaLokacji()
{
	id=-1;
	element=NULL;
	nast=NULL;
}

Lokacja* ListaLokacji::znajdz(int a)
{
	ListaLokacji* aktualny=this;		//zacznij od poczatku
	for (int i=0;i<a;i++)					//przegladaj liste az dojdziesz do wymaganego numeru
	{
		if (aktualny->nast==NULL) return NULL;
		else aktualny=aktualny->nast;
	}
	return aktualny->element;

}

Lokacja::Lokacja()
{
	nazwa="Bezimienna Lokacja";
	opis="Ktoœ zapomnia³ nadaæ opis tej lokacji";
	przedmioty=new ItemList;
	postacie=new CharList;
	for (int i=0;i<6;i++) 
	{
		zamek[i]=0;
		wyjscie[i]=NULL;
	}
	zdGlob = 0;
	jednorazoweZdGlob = 0;
	backgroundMusic = (MidiFiles::MidiFile)-1;
	naturalneOswietlenie=false;
}

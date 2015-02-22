#include "Klasa.h"

extern Klasa** klasy;

Klasa::Klasa(string nazwa, float si, float zr, float zw, float wyt, float zyw)
{
	this->nazwa = nazwa;
	this->si = si;
	this->zr = zr;
	this->zw = zw;
	this->wyt = wyt;
	this->zyw = zyw;
}

Klasa::~Klasa(void)
{
}

float Klasa::getSi(int lvl)
{
	return floor((double)lvl/5) * si;
}

float Klasa::getZr(int lvl)
{
	return floor((double)lvl/5) * zr;
}

float Klasa::getZw(int lvl)
{
	return floor((double)lvl/5) * zw;
}

float Klasa::getWyt(int lvl)
{
	return floor((double)lvl/5) * wyt;
}

float Klasa::getZyw(int lvl)
{
	return floor((double)lvl/5) * zyw;
}

Klasa *getKlasa(KlasaNazwa nazwa)
{
	if (klasy == NULL) return NULL;
	if (nazwa < 0) return klasy[KLASA_BRAK];
	if (nazwa >= ILOSC_KLAS) return klasy[KLASA_BRAK];
	return klasy[nazwa];
}
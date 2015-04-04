#pragma once

#include <iostream>
#include <math.h>
#include "postac.h"

class ListaKomend;
class Lokacja;
enum KierunekSwiata;

extern ListaKomend *listaKomend;

class Gracz: public Postac
{
public:
	Gracz();
	void tworzenie_postaci();

	void ulecz(int ile);
	void dodajEXP(int ile);
	void awansOPoziom();
	int expDoNastPoziomu();
	bool jestGraczem();		//przeslania funkcje wirtualna z Postac
	bool jestUzbrojony();
	
	void sprawdzWymagania(Item* item);
	void hold(wstring cel, int ktory);

	int exp;
	int pktCech;
	int charakter;
	Lokacja* polozenie;
	KierunekSwiata poprzedniePolozenie;
	
private:
	
};
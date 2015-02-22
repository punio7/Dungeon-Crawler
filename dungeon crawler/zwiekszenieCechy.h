#pragma once
#include "status.h"

class Postac;
class Gracz;
enum Cecha;

class zwiekszenieCechy: public Status
{
public:
	zwiekszenieCechy(string nazwa, string opis, string enterMsg, string exitMsg, Cecha cecha, int moc, int czas);

	void aktywujPasyw(Postac *postac);
	void aktywujExplor(Gracz *gracz, int time);
	void aktywujWalka(Postac &posiadacz, Postac &wrog);
	bool isActive();
	bool isPositive();

	Cecha cecha;	//ktora cecha ma zostac zwiekszona?
	int moc;		//o ile ma zostac zwiekszona?
};
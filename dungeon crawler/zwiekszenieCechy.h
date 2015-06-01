#pragma once
#include "Status.h"

class Postac;
class Gracz;
enum Cecha;

class ZwiekszenieCechy: public Status
{
public:
	ZwiekszenieCechy(wstring nazwa, wstring opis, wstring enterMsg, wstring exitMsg, Cecha cecha, int moc, int czas);

	void aktywujPasyw(Postac *postac);
	void aktywujExplor(Gracz *gracz, int time);
	void aktywujWalka(Postac &posiadacz, Postac &wrog);
	bool isActive();
	bool isPositive();

	Cecha cecha;	//ktora cecha ma zostac zwiekszona?
	int moc;		//o ile ma zostac zwiekszona?
};
#pragma once
#include "komenda.h"

class Item;
class Postac;
class Lokacja;
class Gra;

class Look :
	public Komenda
{
public:
	Look(Gra *gra);
	~Look(void);

	void execute(ParseDTO argumenty);
	void manual();

	void LookMiejsce(Lokacja *polozenie);
	void LookMiejsceOswietlone(Lokacja *polozenie);
	void LookMiejsceCiemno(Lokacja *polozenie);
	void LookPrzedmiot(Item *cel);
	void LookPostac(Postac *cel);
};


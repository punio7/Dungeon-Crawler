#pragma once
#include "status.h"

class Postac;
class Gracz;

class Upadek: public Status
{
public:
	int tura;
	int iloscUpadkow;
	
	Upadek();
	void aktywujPasyw(Postac *postac);
	void aktywujWalka(Postac &posiadacz, Postac &wrog);
	bool isActive();							//true je�eli status si� wyczerpa� i nale�y go usun�� z listy status�w
	bool isBattleOnly();						//true je�eli znika po walce
	bool isPositive();

	int turaNastUpadku(Postac &postac);
};
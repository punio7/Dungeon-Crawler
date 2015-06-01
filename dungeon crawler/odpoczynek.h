#pragma once

#include "Status.h"
#include "Gracz.h"

using namespace std;

class StatusOdpoczynek: public Status
{
public:
	StatusOdpoczynek();
	
	void aktywujExplor(Gracz *gracz, int time);		//efekty statusu w trakcie exploracji
	//void aktywujPasywCecha(Postac *postac);
	//void aktywujPasywAtryb(Postac *postac);
	//void aktywujWalka(Walka *walka);
	bool isActive();							//true je�eli status si� wyczerpa� i nale�y go usun�� z listy status�w
	bool isBattleOnly();						//true je�eli znika po walce
	bool isPositive();
};
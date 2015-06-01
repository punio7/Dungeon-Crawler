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
	bool isActive();							//true je¿eli status siê wyczerpa³ i nale¿y go usun¹æ z listy statusów
	bool isBattleOnly();						//true je¿eli znika po walce
	bool isPositive();
};
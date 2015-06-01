#include "Upadek.h"
#include "Gracz.h"
#include "playerMsg.h"

Upadek::Upadek()
{
	tura = 0;
	iloscUpadkow = 0;
}

void Upadek::aktywujPasyw(Postac *postac)
{
	float mod = pow(0.5,iloscUpadkow) * 100; //100, 50, 25, 12.5 itd
	postac->obr_mod -= (100 - (int)mod);
	postac->otrzymywaneObrazenia += iloscUpadkow * 0.1;
}

void Upadek::aktywujWalka(Postac &posiadacz, Postac &wrog)
{
	tura++;
	if (tura > turaNastUpadku(posiadacz))
	{
		iloscUpadkow++;
		posiadacz.currentPanc = ceil((float)posiadacz.currentPanc/2);
		posiadacz.jestGraczem() ? playerMsg(L"Zaczynasz opadaæ z si³.") : playerMsg(L"Przeciwnik wygl¹da na zmêczonego.");
	}
}

bool Upadek::isActive()
{
	return true;
}

bool Upadek::isBattleOnly()
{
	return true;
}

bool Upadek::isPositive()
{
	return false;
}

int Upadek::turaNastUpadku(Postac &postac)
{
	int iloscTur=0;					//pierwszy upadek nastapi po 1*calk_zm turach
	for (int i = 1; i <= iloscUpadkow + 1; i++)		//drugi upadek po 1*calk_zm + 1/2*calk_zm itd.
	{
		iloscTur += (postac.zm_calk) * (pow(0.5,i-1));
	}

	return iloscTur;
}
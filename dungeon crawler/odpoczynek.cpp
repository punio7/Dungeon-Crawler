#include "odpoczynek.h"
#include "playerMsg.h"

StatusOdpoczynek::StatusOdpoczynek()
{
	czas =3;
	nazwa = "odpoczynek";
	opis = "Twoje rany goj¹ siê, kiedy jesteœ poza walk¹.";
	exitMsg = "Czujesz jak¹œ wewnêtrzn¹ pustkê.";
}

void StatusOdpoczynek::aktywujExplor(Gracz *gracz, int time)
{
	if (gracz->currentHP < gracz->zdr_calk)
	{
		//playerMsg("|GOdpoczynek |0.", intToStr(time*((gracz->wyt_calk/5)+(gracz->zyw_calk/20))));
		gracz->ulecz(time*((gracz->wyt_calk/5)+(gracz->zyw_calk/20)));
	}
}

//void StatusOdpoczynek::aktywujPasywCecha(Postac *postac)
//{
//	cout<<"Dostajesz pasywne bonusy do cech"<<endl;
//	postac->sil_bon+=3;
//	postac->zr_bon+=3;
//	postac->zw_bon+=3;
//	postac->wyt_bon+=3;
//	postac->zyw_bon+=3;
//}
//
//void StatusOdpoczynek::aktywujPasywAtryb(Postac *postac)
//{
//	cout<<"Dostajesz pasywne bonusy do atrybutow"<<endl;
//	postac->at_bon+=3;
//	postac->obr_bon+=3;
//	postac->zdr_bon+=3;
//	postac->panc_bon+=3;
//	postac->ochr_bon+=18;
//	postac->zm_bon+=3;
//	postac->dmg_bon+=3;
//
//	postac->at_mod+=100;
//	postac->obr_mod+=100;
//	postac->zdr_mod+=100;
//	postac->panc_mod+=100;
//	postac->zm_mod+=100;
//	postac->dmg_mod+=100;
//}
//
//void StatusOdpoczynek::aktywujWalka(Walka *walka)
//{
//	cout<<"Zmniejszenie licznika czasu o 1"<<endl;
//	czas--;
//}

bool StatusOdpoczynek::isActive()
{
	return true;
}

bool StatusOdpoczynek::isBattleOnly()
{
	return false;
}

bool StatusOdpoczynek::isPositive()
{
	return true;
}
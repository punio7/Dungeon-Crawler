#include "ZwiekszenieCechy.h"
#include "Gracz.h"

ZwiekszenieCechy::ZwiekszenieCechy(wstring nazwa, wstring opis, wstring enterMsg, wstring exitMsg, Cecha cecha, int moc, int czas)
{
	this->nazwa = nazwa;
	this->opis = opis;
	this->enterMsg = enterMsg;
	this->exitMsg = exitMsg;
	this->cecha = cecha;
	this->moc = moc;
	this->czas = czas;
}

void ZwiekszenieCechy::aktywujPasyw(Postac *postac)
{
	switch (cecha)
	{
	case SILA:
		postac->sil_bon += moc;
		break;
	case ZRECZNOSC:
		postac->zr_bon += moc;
		break;
	case ZWINNOSC:
		postac->zw_bon += moc;
		break;
	case WYTRZYMALOSC:
		postac->wyt_bon += moc;
		break;
	case ZYWOTNOSC:
		postac->zyw_bon += moc;
		break;
	default:
		break;
	}
}

void ZwiekszenieCechy::aktywujExplor(Gracz *gracz, int time)
{
	czas -= time;
}

void ZwiekszenieCechy::aktywujWalka(Postac &posiadacz, Postac &wrog)
{
	czas--;
}

bool ZwiekszenieCechy::isActive()
{
	if (czas > 0) return true;
	else return false;
}

bool ZwiekszenieCechy::isPositive()
{
	if (moc > 0) return true;
	else return false;
}
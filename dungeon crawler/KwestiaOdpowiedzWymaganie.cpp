#include "KwestiaOdpowiedzWymaganie.h"
#include "gra.h"
#include "item.h"
#include "Quest.h"
#include "zdarzeniaGlobalne.h"


KwestiaOdpowiedzWymaganie::KwestiaOdpowiedzWymaganie(KwestiaOdpowiedzWymaganieTyp::KwestiaOdpowiedzWymaganieEnum typWymagania, vector<int> argumenty)
{
	this->typWymagania = typWymagania;
	this->argumenty = argumenty;
}


KwestiaOdpowiedzWymaganie::~KwestiaOdpowiedzWymaganie()
{
}

bool KwestiaOdpowiedzWymaganie::czySpelnia(Gra *gra)
{
	using namespace KwestiaOdpowiedzWymaganieTyp;
	int nrQuesta;

	switch (typWymagania)
	{
	case WymaganieQuestFaza:
		nrQuesta = (argumenty.back());
		argumenty.pop_back();
		for (int faza : argumenty)
		{
			if (gra->questy[nrQuesta]->obecnaFaza() == faza)
			{
				argumenty.push_back(nrQuesta);
				return true;
			}
		}
		argumenty.push_back(nrQuesta);
		return false;
		break;
	case WymaganieGraczZloto:
		return gra->gracz.zloto >= argumenty[0];
		break;
	case WymaganieGraczItem:
		return gra->gracz.przedmioty->znajdz(argumenty[0], 1) != NULL;
		break;
	case WymaganieGraczItemIlosc:
		return gra->gracz.przedmioty->znajdz(argumenty[0], argumenty[1]) != NULL;
		break;
	case WymaganieGraczRasa:
		return (gra->gracz.rasa->rasaEnum & argumenty[0]) != 0;
	case WymaganieZdarzenieGlobalne:
		return true;
	default:
		throw new wstring(L"Nieznany typ wymagania odpowiedzi w rozmowie.");
		break;
	}
}

void KwestiaOdpowiedzWymaganie::zabierzWymagane(Gra* gra, Postac *npc)
{
	using namespace KwestiaOdpowiedzWymaganieTyp;
	Item* przedmiot;
	
	switch (typWymagania)
	{
	case WymaganieQuestFaza:
		break;
	case WymaganieGraczZloto:
		gra->gracz.usunZloto(argumenty[0]);
		npc->dodajZloto(argumenty[0]);
		playerMsg(L"|YOddajesz |0 szt. z³ota.", intToStr(argumenty[0]));
		break;
	case WymaganieGraczItem:
		przedmiot = (gra->gracz.przedmioty)->znajdz(argumenty[0], 1);
		gra->gracz.usunPrzedmiot(przedmiot);
		npc->dodajPrzedmiot(przedmiot);
		playerMsg(L"|YOdda³eœ |0.", przedmiot->nazwa);
		break;
	case WymaganieGraczItemIlosc:
		for (int i = 0; i < argumenty[1]; i++)
		{
			przedmiot = (gra->gracz.przedmioty)->znajdz(argumenty[0], 1);
			gra->gracz.usunPrzedmiot(przedmiot);
			npc->dodajPrzedmiot(przedmiot);
			playerMsg(L"|YOdda³eœ |0.", przedmiot->nazwa);
		}
		break;
	case WymaganieGraczRasa:
		break;
	case WymaganieZdarzenieGlobalne:
		wywolajZdarzenieGlobalne(argumenty[0]);
		break;
	default:
		throw new wstring(L"Nieznany typ wymagania odpowiedzi w rozmowie.");
		break;
	}
}

#pragma once
#include <vector>

using namespace std;

class Gra;
class Postac;

namespace KwestiaOdpowiedzWymaganieTyp
{
	enum KwestiaOdpowiedzWymaganieEnum
	{
		WymaganieQuestFaza,
		WymaganieGraczZloto,
		WymaganieGraczItem,
		WymaganieGraczItemIlosc,
		WymaganieGraczRasa,
		WymaganieZdarzenieGlobalne		//praktycznie nie wymaganie, ale uruchamia zdarzenie globalne
	};
}

class KwestiaOdpowiedzWymaganie
{
public:
	KwestiaOdpowiedzWymaganie(KwestiaOdpowiedzWymaganieTyp::KwestiaOdpowiedzWymaganieEnum typWymagania, vector<int> argumenty);
	~KwestiaOdpowiedzWymaganie();

	bool czySpelnia(Gra* gra);
	void zabierzWymagane(Gra* gra, Postac* npc);
private:
	KwestiaOdpowiedzWymaganieTyp::KwestiaOdpowiedzWymaganieEnum typWymagania;
	vector<int> argumenty;
};


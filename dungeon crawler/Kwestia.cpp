#include "Kwestia.h"
#include "KwestiaOdpowiedzWymaganie.h"

using namespace KwestiaOdpowiedzWymaganieTyp;
using namespace KwestiaNagrody;

Kwestia::Kwestia(void)
{
	nagrody.clear();
}

Kwestia::Kwestia(int numer, int domyslnaNastepna, wstring tekst)
{
	Kwestia::numer=numer;
	Kwestia::domyslnaNastepna=domyslnaNastepna;
	Kwestia::tekst=tekst;
}

Kwestia::~Kwestia(void)
{
	for (KwestiaOdpowiedz* aktualna : odpowiedzi)
	{
		delete aktualna;
	}
}

void Kwestia::usunOdpowiedz(int nast)
{
	if (nast<1) return;		//nast musi byc >1

	for (auto odp = odpowiedzi.begin(); odp != odpowiedzi.end();)
	{
		if ( (*odp)->nast == nast )
		{
			odp = odpowiedzi.erase(odp);
		}
		else
		{
			odp++;
		}
	}
}

KwestiaOdpowiedz* Kwestia::dodajOdpowiedz(wstring tekst, int nastepnaKwestia, int charakter)
{
	KwestiaOdpowiedz *odpowiedz = new KwestiaOdpowiedz();
	odpowiedz->tekst = tekst;
	odpowiedz->nast = nastepnaKwestia;
	odpowiedz->charakter = charakter;
	odpowiedzi.push_back(odpowiedz);
	return odpowiedz;
}

Kwestia* Kwestia::dodajNagrodeQuestFaza(int quest, int faza)
{
	vector<int> nagroda(3, 0);
	nagroda[0] = KwestiaNagrody::NagrodaQuestFaza;
	nagroda[1] = quest;
	nagroda[2] = faza;
	nagrody.push_back(nagroda);
	return this;
}

Kwestia* Kwestia::dodajNagrodeGraczDoswiadczenie(int iloscDoswiadczenia)
{
	vector<int> nagroda(2, 0);
	nagroda[0] = KwestiaNagrody::NagrodaGraczDoswiadczenie;
	nagroda[1] = iloscDoswiadczenia;
	nagrody.push_back(nagroda);
	return this;
}

Kwestia* Kwestia::dodajNagrodeGraczZloto(int iloscZlota)
{
	vector<int> nagroda(2, 0);
	nagroda[0] = KwestiaNagrody::NagrodaGraczZloto;
	nagroda[1] = iloscZlota;
	nagrody.push_back(nagroda);
	return this;
}

Kwestia* Kwestia::dodajNagrodeGraczItem(int idItema)
{
	vector<int> nagroda(2, 0);
	nagroda[0] = KwestiaNagrody::NagrodaGraczItem;
	nagroda[1] = idItema;
	nagrody.push_back(nagroda);
	return this;
}

Kwestia* Kwestia::dodajNagrodeZdarzenieGlobalne(int idZdarzeniaGlobalnego)
{
	vector<int> nagroda(2, 0);
	nagroda[0] = KwestiaNagrody::NagrodaZdarzenieGlobalne;
	nagroda[1] = idZdarzeniaGlobalnego;
	nagrody.push_back(nagroda);
	return this;
}


KwestiaOdpowiedz::KwestiaOdpowiedz()
{
	nast=1;
	charakter=0;
	wymagania.clear();
}

KwestiaOdpowiedz::KwestiaOdpowiedz(wstring tekst, int nast, int charakter)
{
	KwestiaOdpowiedz::tekst=tekst;
	KwestiaOdpowiedz::nast=nast;
	KwestiaOdpowiedz::charakter=charakter;
}

KwestiaOdpowiedz::~KwestiaOdpowiedz()
{
	for (KwestiaOdpowiedzWymaganie* aktualny : wymagania)
	{
		delete aktualny;
	}
}


KwestiaOdpowiedz* KwestiaOdpowiedz::DodajWymaganieQuestFaza(int quest, vector<int> fazy)
{
	vector<int> wektorWymagan(fazy);
	wektorWymagan.push_back(quest); // {numery faz, ..., numer questa}
	KwestiaOdpowiedzWymaganie* wymaganie = new KwestiaOdpowiedzWymaganie(WymaganieQuestFaza, wektorWymagan);
	wymagania.push_back(wymaganie);
	return this;
}

KwestiaOdpowiedz* KwestiaOdpowiedz::DodajWymaganieZloto(int ilosc)
{
	KwestiaOdpowiedzWymaganie* wymaganie = new KwestiaOdpowiedzWymaganie(WymaganieGraczZloto, { ilosc });
	wymagania.push_back(wymaganie);
	return this;
}

KwestiaOdpowiedz* KwestiaOdpowiedz::DodajWymaganieItem(int idItema)
{
	KwestiaOdpowiedzWymaganie* wymaganie = new KwestiaOdpowiedzWymaganie(WymaganieGraczItem, { idItema });
	wymagania.push_back(wymaganie);
	return this;
}

KwestiaOdpowiedz* KwestiaOdpowiedz::DodajWymaganieItemIlosc(int idItema, int ilosc)
{
	KwestiaOdpowiedzWymaganie* wymaganie = new KwestiaOdpowiedzWymaganie(WymaganieGraczItemIlosc, { idItema, ilosc });
	wymagania.push_back(wymaganie);
	return this;
}

KwestiaOdpowiedz* KwestiaOdpowiedz::DodajWymaganieRasa(int maskaRas)
{
	KwestiaOdpowiedzWymaganie* wymaganie = new KwestiaOdpowiedzWymaganie(WymaganieGraczRasa, {maskaRas} );
	wymagania.push_back(wymaganie);
	return this;
}

KwestiaOdpowiedz* KwestiaOdpowiedz::DodajWymaganieZdarzenieGlobalne(int numer)
{
	KwestiaOdpowiedzWymaganie* wymaganie = new KwestiaOdpowiedzWymaganie(WymaganieZdarzenieGlobalne, { numer });
	wymagania.push_back(wymaganie);
	return this;
}
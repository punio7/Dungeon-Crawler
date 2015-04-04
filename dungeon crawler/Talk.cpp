#include "Talk.h"
#include "gra.h"
#include "item.h"
#include "Quest.h"
#include "Rozmowa.h"
#include "KwestiaOdpowiedzWymaganie.h"
#include "Kwestia.h"
#include "Lokacja.h"
#include "Kill.h"

extern ListaKomend *listaKomend;

Talk::Talk(Gra *gra):
	Komenda(gra)
{
	nazwa = L"talk";
}


Talk::~Talk(void)
{
}

void Talk::execute(ParseDTO argumenty)
{
	talk(gra->gracz.polozenie->postacie->znajdz(argumenty.argument1, argumenty.ktory1));
}

void Talk::talk(Postac *npc)
{
	if (!npc)
	{
		playerMsg(L"Tu nie ma nikogo takiego.");
		return;
	}

	if ( !npc->chceRozmawiac() )
	{
		playerMsg(L"|^|0 nie ma nic do powiedzenia.", npc->imie);
		return;
	}

	Rozmowa* rozmowa = npc->wskRozmowa();

	while (1)	//ca³a rozmowa jest realizowana w pêtli.
	{
		if ( rozmowa->obecnaKwestia == -1 )		//obecna kwestia=-1 oznacza koniec rozmowy
		{										//poniewaz -1 nie jest poprawnym numerem kwestii
			rozmowa->obecnaKwestia = rozmowa->domyslnaKwestia;		//musimy zmienic numer obecnej kwestii przed wyjsciem z rozmowy
			break;
		}

		if ( rozmowa->obecnaKwestia == -2 )
		{
			playerMsg(L"|^|0 dobywa broni i rzuca siê na ciebie!", npc->imie);
			npc->agresywny=true;
			dynamic_cast<Kill*>(listaKomend->komendy[COMM_KILL])->rozpocznijWalke(npc);
			break;
		}

		Kwestia* kwestia = rozmowa->znajdzObecnaKwestia();
		rozmowa->domyslnaKwestia = kwestia->domyslnaNastepna;

		dajNagrody(kwestia, npc);	//nagrody za uruchomienie danej kwestii

		playerMsg(L"|B|^|0:", npc->imie);
		playerMsg(kwestia->tekst);
		playerMsg(L"");

		wypiszMozliweOdpowiedzi(kwestia); //wypisuj mozliwe dla gracza odpowiedzi

		KwestiaOdpowiedz* odpowiedz = NULL;
		while (!odpowiedz)
		{
			int wybor;
			wcin>>wybor;
			wcin.clear();
			wcin.ignore(999,'\n');
			wcin.sync();
			odpowiedz = znajdzOdpowiedz(rozmowa, wybor);
		}

		zabierzWymagane(odpowiedz, npc); //zabiera graczowi rzeczy potrzebne do danej odpowiedzi

		//gracz przeszedl wysztskie wymagania, nastepuje zmiana kwestii
		rozmowa->obecnaKwestia = odpowiedz->nast;
	}
}

void Talk::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   talk(tal)\n\n"
			 L"U¿ycia:\n\n"
			 L"   talk <nazwa_postaci> - gracz rozpoczyna rozmowê ze wskazan¹ postaci¹ (o ile nie chce ci ona wyd³ubaæ oczu).\n\n"
			 L"SprawdŸ równie¿:\n"
			 L"   examine, consider, kill, journal");
}

void Talk::dajNagrody(Kwestia *kwestia, Postac *npc)
{
	using namespace KwestiaNagrody;

	for (vector<int> nagroda : kwestia->nagrody)
	{
		KwestiaNagrodyEnum typ = (KwestiaNagrodyEnum)nagroda[0];
		Item* przedmiot = NULL;

		switch (typ)
		{
		case KwestiaNagrody::NagrodaQuestFaza:
			if (nagroda[1] > LICZBA_QUESTOW)
			{
				playerMsg(L"|RB³¹d, nie mo¿na spe³niæ wymogów questu |0, dany quest nie istnieje.", intToStr(nagroda[1]));
			}
			else
			{
				gra->questy[nagroda[1]]->spelnijRozmowa(nagroda[2]);
			}
			break;
		case KwestiaNagrody::NagrodaGraczDoswiadczenie:
			playerMsg(L"|YOtrzymano |0 punktów doœwiadczenia", intToStr(nagroda[1]));
			gra->gracz.dodajEXP(nagroda[1]);
			break;
		case KwestiaNagrody::NagrodaGraczZloto:
			if (nagroda[1] > npc->zloto)
			{										//jezeli npc nie ma wystarczajaco zlota aby wyplacic nagrode
				gra->gracz.dodajZloto(npc->zloto);	//to wyplaci tyle ile ma
				playerMsg(L"|YOtrzymano |0 szt. z³ota.", intToStr(npc->zloto));
				npc->usunZloto(npc->zloto);
			}
			else 
			{
				gra->gracz.dodajZloto(nagroda[1]);
				npc->usunZloto(nagroda[1]);
				playerMsg(L"|YOtrzymano |0 szt. z³ota.", intToStr(nagroda[1]));
			}
			break;
		case KwestiaNagrody::NagrodaGraczItem:
			if (Item* przedmiot = (npc->przedmioty)->znajdz(nagroda[1], 1))
			{
				npc->przedmioty->usun(przedmiot);
				gra->gracz.dodajPrzedmiot(przedmiot);
				playerMsg(L"|YOtrzyma³eœ |0.", przedmiot->nazwa);
			}
			break;
		case KwestiaNagrody::NagrodaZdarzenieGlobalne:
			gra->zdarzenieGlobalne(nagroda[1]);
			//TODO Rozpatrzyc mozliwoc przerywania rozmowy gdy Zdarzenie zwroci TRUE
			break;
		default:
			break;
		}
	}
}

void Talk::wypiszMozliweOdpowiedzi(Kwestia *kwestia)
{
	int i=1;	//numeracja mozliwych odpowiedzi	

	for (KwestiaOdpowiedz *aktualny : kwestia->odpowiedzi)
	{
		if (graczSpelniaWymaganiaOdpowiedzi(aktualny))
		{	//jezeli gracz nie spelnia wymagan jakiejs odpowiedzi to nie zostanie ona wypisana
			playerMsg(L"|0. |1", intToStr(i), aktualny->tekst);	//np. "1. Oddawaj swoje zloto!"
			i++;
		}
	}
}

bool Talk::graczSpelniaWymaganiaOdpowiedzi(KwestiaOdpowiedz* odpowiedz)
{
	bool zwracany = true;

	for (KwestiaOdpowiedzWymaganie* wymaganie : odpowiedz->wymagania)
	{
		zwracany &= wymaganie->czySpelnia(gra);
	}

	return zwracany;
}

KwestiaOdpowiedz* Talk::znajdzOdpowiedz(Rozmowa* rozmowa, int wybor)
{
	if (wybor<1) return NULL;

	int i=0;	//liczy znaleznione mozliwe odpowiedzi
	Kwestia* kwestia = rozmowa->znajdzObecnaKwestia();

	for (KwestiaOdpowiedz *aktualny : kwestia->odpowiedzi)
	{
		if (graczSpelniaWymaganiaOdpowiedzi(aktualny)) i++;	//inkrementujemy licznik odpowiedzi tylko jezeli aktualna odpowidz byla mozliwa do udzielenia
		if (i >= wybor)		//jezeli licznik odpowiedzi == wybor to znaczy, ze znalezlismy szukany element
		{
			return aktualny;
		}
	}

	return NULL;
}

void Talk::zabierzWymagane(KwestiaOdpowiedz *odpowiedz, Postac *npc)
{
	using namespace KwestiaOdpowiedzWymaganieTyp;

	for (KwestiaOdpowiedzWymaganie* wymaganie : odpowiedz->wymagania)
	{
		wymaganie->zabierzWymagane(gra, npc);
	}

	if (odpowiedz->charakter)
	{

		//todo zmiana charakteru

	}
}
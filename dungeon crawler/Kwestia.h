#pragma once

#include <string>
#include <list>
#include <vector>

using namespace std;

class KwestiaOdpowiedzWymaganie;

namespace KwestiaNagrody
{
	enum KwestiaNagrodyEnum
	{
		NagrodaQuestFaza,
		NagrodaGraczDoswiadczenie,
		NagrodaGraczZloto,
		NagrodaGraczItem,
		NagrodaZdarzenieGlobalne
	};
}

class KwestiaOdpowiedz
{
public:
	KwestiaOdpowiedz();
	KwestiaOdpowiedz(wstring tekst, int nast, int charakter=0);
	~KwestiaOdpowiedz();
	KwestiaOdpowiedz* DodajWymaganieQuestFaza(int quest, vector<int> fazy);
	KwestiaOdpowiedz* DodajWymaganieZloto(int ilosc);
	KwestiaOdpowiedz* DodajWymaganieItem(int idItema);
	KwestiaOdpowiedz* DodajWymaganieItemIlosc(int idItema, int ilosc);
	KwestiaOdpowiedz* DodajWymaganieRasa(int maskaRas);
	KwestiaOdpowiedz* DodajWymaganieZdarzenieGlobalne(int numer);

	wstring tekst;
	int nast;				//numer nastepnej kwestii, -1- koniec rozmowy, -2- koneic rozmowy i walka
	int charakter;			//wypowiadanie tej odpowiedzi zmienia charakter
	list<KwestiaOdpowiedzWymaganie*> wymagania;	//wymagania danej odpowiedzi
};


class Kwestia
{
public:
	Kwestia(void);
	Kwestia(int numer, int domyslnaNastepna, wstring tekst);
	~Kwestia(void);
	//usuwa z kwestii wszystkie odpowiedzi prowadzace do kwestii o numerze nast
	void usunOdpowiedz(int nast);
	KwestiaOdpowiedz* dodajOdpowiedz(wstring tekst, int nastepnaKwestia, int charakter = 0);
	//dodaje nagrode do listy nagrod, kazda nagroda ma wlasne argumenty
	//Kwestia* dodajNagrode(KwestiaNagrody::KwestiaNagrodyEnum, int arg1, int arg2=0, int arg3=0, int arg4=0);
	Kwestia* dodajNagrodeQuestFaza(int quest, int faza);
	Kwestia* dodajNagrodeGraczDoswiadczenie(int iloscDoswiadczenia);
	Kwestia* dodajNagrodeGraczZloto(int iloscZlota);
	Kwestia* dodajNagrodeGraczItem(int idItemu);
	Kwestia* dodajNagrodeZdarzenieGlobalne(int idZdarzeniaGlobalnego);

	int numer;									//numer id kwestii
	int domyslnaNastepna;						//zmienia kwestie startowa rozmowy
	//KwestiaListaOdpowiedzi odpowiedzi;			//odpowiedzi
	list<KwestiaOdpowiedz*> odpowiedzi;			//odpowiedzi ktorych moze udzielic gracz
	//int przedmiot[MAX_PRZEDMIOTY_KWESTIA];		//id przedmiotow dawanych graczowi przy rozpoczeciu kwestii, id=0 -nic nie dostaje
	list<vector<int>> nagrody;					//nagrody za przejscie do danej kwestii
	//int zloto;									//zloto dawane graczowi przy rozpoczeciu kwestii
	//int exp;									//exp dawany graczowi przy rozpoczeciu kwestii
	//int quest;									//wskazuje, który quest ulegnie zmianie, 0- nic sie nie dzieje
	//int questFaza;								//zmienia faze wskazanego wyzej questu na podana tutaj
	wstring tekst;								//w³aœciwy tekst kwestii

};

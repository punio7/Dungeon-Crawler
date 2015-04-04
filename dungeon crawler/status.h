#pragma once

#include <string>
#include <list>

class Postac;
class Gracz;

using namespace std;

class Status
{
public:
	Status();
	
	virtual void aktywujPasyw(Postac *postac);		//efekty pasywne
	virtual void aktywujExplor(Gracz *gracz, int time);		//efekty statusu w trakcie exploracji
	virtual void aktywujWalka(Postac &posiadaczm, Postac &wrog);				//efekty statusu w trakcie walki
	virtual bool isActive();							//true je¿eli status siê wyczerpa³ i nale¿y go usun¹æ z listy statusów
	virtual bool isBattleOnly();						//true je¿eli znika po walce
	virtual bool isPositive();							//true je¿eli to status pozytywny (buff) false je¿eli to debuff

	wstring nazwa;
	wstring opis;
	wstring enterMsg;	//wiadomosc wyswietlana kiedy gracz otrzymuje dany stan
	wstring exitMsg;		//wiadomosc wysietlana kiedy gracz wychodzi z danego stanu
	int czas;
	//item *zrodlo;		//przedmiot bedacy zrodlem statusu albo NULL, jezeli przedmiot ten zostanie
};

class StatusList : public list<Status*>
{
public:
	StatusList();
	~StatusList();
	wstring wypisz();
	void dodaj(Status* status);
	void usun(Status* status);			//usuwa status z listy ale nie usuwa go z pamieci
	void usunPierwszy();				//kasuje z listy pierwszy status nie usuwa statusu z pamieci
	bool pusta();						//True je¿eli lista jest pusta
	Status* znajdz(wstring szukany, int ktory=1);	//zwraca wskaŸnik na status z listy o zadanej nazwie, NULL jezeli nie ma takiego
	Status* znajdz(int ktory);						//zwraca status bêd¹cy na ktory-m miejscu na liscie
};
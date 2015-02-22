#pragma once
#include "komenda.h"

class Postac;
class Kwestia;
class Rozmowa;
class KwestiaOdpowiedz;

class Talk :
	public Komenda
{
public:
	Talk(Gra *gra);
	~Talk(void);

	void execute(ParseDTO argumenty);
	void manual();
	//rozpoczyna rozmowe z danym npc, sprawdza poprawnosc wskaznika
	void talk(Postac *npc);
private:
	//daje graczowi wszystkie nagrody za uruchomienie kwestii
	void dajNagrody(Kwestia *kwestia, Postac *npc);
	//wypisuje mozliwe odpowiedzi gracza w danej kwestii
	void wypiszMozliweOdpowiedzi(Kwestia *kwestia);
	//sprawdza czy garcz spelnil wymagania danej odpowiedzi, przedmioty, questy itp.
	bool graczSpelniaWymaganiaOdpowiedzi(KwestiaOdpowiedz* odpowiedz);
	//szuka odpowiedzi o numerze wpisanym przy gracza, bierze pod uwage tylko odpowiedzi, ktorych wymagania gracz spelnil
	KwestiaOdpowiedz* znajdzOdpowiedz(Rozmowa* rozmowa, int wybor);
	//zabiera graczowi rzeczy wymagane do danej odpowiedzi
	void zabierzWymagane(KwestiaOdpowiedz *odpowiedz, Postac *npc);
};


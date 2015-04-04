#pragma once
#include "postac.h"

class Rozmowa;

using namespace std;

class PostacNpc :
	public Postac
{
public:
	PostacNpc(void);
	~PostacNpc(void);
	Rozmowa* wskRozmowa();
	Kwestia* wskObecnaKwestia();
	Item *sklep;
	bool chceRozmawiac();	//zwraca zawsze true dla tej klasy
	bool jestRozmowny();	//rozmowna postac wymusza rozmowe przy pierwszym spotkaniu
	bool jestTrenerem();
	bool jestKupcem();
	wstring list();			//wypisuje liste przedmiotow na sprzedaz
	void setSklep(Item* sklep);	//ustawia magazyn sklepowy
	void sklepSprzedaj(Item *item, int cena);	//usuwa item ze sklepu i dodaje zloto
	void sklepKup(Item *item, int cena);		//dodaje item do sklepu i odejmuje zloto
	Item* sklepZnajdz(wstring cel, int ktory);	//znajduje w sklepie item
	int trener(Cecha cecha);
	void ustawRozmowny(bool cel);
	void dodajKwestie(Kwestia* kwestia);

	bool rozmowny;	//jezeli true, to postac automatecznie zacznie rozmowe przy pierwszym zobaczeniu gracza
	Rozmowa* rozmowa;
	int trening[5];
};


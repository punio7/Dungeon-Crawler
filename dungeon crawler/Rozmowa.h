#pragma once
#include <list>

using namespace std;

class Kwestia;

class Rozmowa
{
public:
	Rozmowa(void);
	~Rozmowa(void);

	//zwraca wskaznik na obecna kwestie
	Kwestia* znajdzObecnaKwestia();
	//zwraca wskaznik na kwestie o numerze
	Kwestia* znajdzKwestie(int numer);
	//dodaje do listy kwestii podana kwestie
	Kwestia* dodajKwestie(Kwestia* kwestia);

	list<Kwestia*> kwestie;
	//obecna kwestia w rozmowie, -1- koniec rozmowy -2-koniec rozmowy i walka
	int obecnaKwestia;
	//kwestia ladowana na poczatku rozmowy
	int domyslnaKwestia;
};


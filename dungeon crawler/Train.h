#pragma once
#include "komenda.h"

class Postac;
enum Cecha;

class Train :
	public Komenda
{
public:
	Train(Gra *gra);
	~Train(void);

	void execute(ParseDTO argumenty);
	void manual();

	//zwraca ceche ktorej nazwa jest zawarta w stringu
	Cecha znajdzCeche(string cecha);
	//wypisuje wszystkie mozliwe cechy ktore moze trenowac dany trener
	void wypiszMozliwyTrening(Postac *trener);
	void train(Cecha, Postac *trener);
};


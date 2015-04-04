#pragma once
#include "komenda.h"

class Postac;

class Buy :
	public Komenda
{
public:
	Buy(Gra *gra);
	~Buy(void);

	void execute(ParseDTO argumenty);
	void manual();

	//szuka kupca o wskazanej nazwie, jezeli nic nie podano szuka dowolnego, sprawdza czy znaleziony jest kupcem, sprawdza czy cokolwiek znaleziono, wypisuje komunikaty
	Postac *znajdzKupca(wstring kupiec, int ktory);
};


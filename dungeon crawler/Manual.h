#pragma once
#include "komenda.h"

class Manual :
	public Komenda
{
public:
	Manual(Gra *gra);
	~Manual(void);

	void execute(ParseDTO argumenty);
	void manual();

	void wyswietlListeKomend();
};


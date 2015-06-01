#pragma once
#include <string>
#include "ParseDTO.h"
#include "playerMsg.h"

class Gra;

class Komenda
{
public:
	Komenda(Gra *gra);
	~Komenda(void);
	virtual void execute(ParseDTO argumenty);
	virtual void manual();

	Gra *gra;
	wstring nazwa;	//nazwa wyswietlana w liscie komend komendy manual, pusty wstring aby ukryc komende
};


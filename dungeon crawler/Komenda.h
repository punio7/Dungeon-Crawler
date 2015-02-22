#pragma once

#include <string>
#include <iostream>
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
	string nazwa;	//nazwa wyswietlana w liscie komend komendy manual, pusty string aby ukryc komende
};


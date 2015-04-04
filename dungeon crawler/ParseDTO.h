#pragma once

#include <string>
#include "kierunkiSwiata.h"
#include "EnumKomendy.h"

using namespace std;

class ParseDTO
{
public:

	wstring argument1, argument2;
	KierunekSwiata kierunek1;
	Ekomenda komenda1;
	int ktory1, ktory2;

	ParseDTO(void);
	~ParseDTO(void);
	void clear();
};


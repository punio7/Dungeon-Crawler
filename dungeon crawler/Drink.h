#pragma once
#include "komenda.h"
class Drink :
	public Komenda
{
public:
	Drink(Gra *gra);
	~Drink(void);

	void execute(ParseDTO argumenty);
	void manual();
};


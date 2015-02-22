#pragma once
#include "komenda.h"
class Sell :
	public Komenda
{
public:
	Sell(Gra *gra);
	~Sell(void);

	void execute(ParseDTO argumenty);
	void manual();
};


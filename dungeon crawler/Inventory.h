#pragma once
#include "komenda.h"
class Inventory :
	public Komenda
{
public:
	Inventory(Gra *gra);
	~Inventory(void);

	void execute(ParseDTO argumenty);
	void manual();
};


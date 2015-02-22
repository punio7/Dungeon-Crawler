#pragma once
#include "komenda.h"
class Wield :
	public Komenda
{
public:
	Wield(Gra *gra);
	~Wield(void);

	void execute(ParseDTO argumenty);
	void manual();
};


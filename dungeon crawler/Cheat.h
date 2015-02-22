#pragma once
#include "komenda.h"
class Cheat :
	public Komenda
{
public:
	Cheat(Gra *gra);
	~Cheat(void);

	void execute(ParseDTO argumenty);
	void manual();
};


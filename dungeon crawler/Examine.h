#pragma once
#include "komenda.h"
class Examine :
	public Komenda
{
public:
	Examine(Gra *gra);
	~Examine(void);

	void execute(ParseDTO argumenty);
	void manual();
};


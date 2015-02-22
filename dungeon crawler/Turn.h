#pragma once
#include "komenda.h"
class Turn :
	public Komenda
{
public:
	Turn(Gra *gra);
	~Turn(void);

	void execute(ParseDTO argumenty);
	void manual();
};


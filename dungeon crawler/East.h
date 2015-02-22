#pragma once
#include "komenda.h"
class East :
	public Komenda
{
public:
	East(Gra *gra);
	~East(void);

	void execute(ParseDTO argumenty);
	void manual();
};


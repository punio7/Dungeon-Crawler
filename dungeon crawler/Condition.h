#pragma once
#include "komenda.h"
class Condition :
	public Komenda
{
public:
	Condition(Gra *gra);
	~Condition(void);

	void execute(ParseDTO argumenty);
	void manual();
};


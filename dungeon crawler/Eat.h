#pragma once
#include "komenda.h"
class Eat :
	public Komenda
{
public:
	Eat(Gra *gra);
	~Eat(void);

	void execute(ParseDTO argumenty);
	void manual();
};


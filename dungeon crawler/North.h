#pragma once
#include "komenda.h"
class North :
	public Komenda
{
public:
	North(Gra *gra);
	~North(void);

	void execute(ParseDTO argumenty);
	void manual();
};


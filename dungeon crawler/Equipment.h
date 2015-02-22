#pragma once
#include "komenda.h"
class Equipment :
	public Komenda
{
public:
	Equipment(Gra *gra);
	~Equipment(void);

	void execute(ParseDTO argumenty);
	void manual();
	void equipment();
};


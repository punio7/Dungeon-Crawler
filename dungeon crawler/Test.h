#pragma once
#include "komenda.h"
class Test :
	public Komenda
{
public:
	Test(Gra *gra);
	~Test(void);

	void execute(ParseDTO argumenty);
	void manual();
};


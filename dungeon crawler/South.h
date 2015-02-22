#pragma once
#include "komenda.h"
class South :
	public Komenda
{
public:
	South(Gra *gra);
	~South(void);

	void execute(ParseDTO argumenty);
	void manual();
};


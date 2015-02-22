#pragma once
#include "komenda.h"
class Down :
	public Komenda
{
public:
	Down(Gra *gra);
	~Down(void);

	void execute(ParseDTO argumenty);
	void manual();
};


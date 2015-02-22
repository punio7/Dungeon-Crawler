#pragma once
#include "komenda.h"
class Quit :
	public Komenda
{
public:
	Quit(Gra *gra);
	~Quit(void);

	void execute(ParseDTO argumenty);
	void manual();
};


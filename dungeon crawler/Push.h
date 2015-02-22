#pragma once
#include "komenda.h"

class Push :
	public Komenda
{
public:
	Push(Gra *gra);
	~Push(void);

	void execute(ParseDTO argumenty);
	void manual();
};


#pragma once
#include "komenda.h"
class West :
	public Komenda
{
public:
	West(Gra *gra);
	~West(void);

	void execute(ParseDTO argumenty);
	void manual();
};


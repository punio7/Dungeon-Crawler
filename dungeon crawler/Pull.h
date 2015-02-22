#pragma once
#include "komenda.h"
class Pull :
	public Komenda
{
public:
	Pull(Gra *gra);
	~Pull(void);

	void execute(ParseDTO argumenty);
	void manual();
};


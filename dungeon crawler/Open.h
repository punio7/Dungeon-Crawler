#pragma once
#include "komenda.h"
class Open :
	public Komenda
{
public:
	Open(Gra *gra);
	~Open(void);

	void execute(ParseDTO argumenty);
	void manual();
};


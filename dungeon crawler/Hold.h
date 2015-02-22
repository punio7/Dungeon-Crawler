#pragma once
#include "komenda.h"
class Hold :
	public Komenda
{
public:
	Hold(Gra *gra);
	~Hold(void);

	void execute(ParseDTO argumenty);
	void manual();
};


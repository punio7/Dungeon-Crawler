#pragma once
#include "komenda.h"
class Up :
	public Komenda
{
public:
	Up(Gra *gra);
	~Up(void);

	void execute(ParseDTO argumenty);
	void manual();
};


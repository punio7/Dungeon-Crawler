#pragma once
#include "komenda.h"
class Offer :
	public Komenda
{
public:
	Offer(Gra *gra);
	~Offer(void);

	void execute(ParseDTO argumenty);
	void manual();
};


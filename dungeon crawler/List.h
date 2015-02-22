#pragma once
#include "komenda.h"
class List :
	public Komenda
{
public:
	List(Gra *gra);
	~List(void);

	void execute(ParseDTO argumenty);
	void manual();
};


#pragma once
#include "komenda.h"
class KomendaTemplate :
	public Komenda
{
public:
	KomendaTemplate(Gra *gra);
	~KomendaTemplate(void);

	void execute(ParseDTO argumenty);
	void manual();
};


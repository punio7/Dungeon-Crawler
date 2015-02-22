#pragma once
#include "komenda.h"

class Postac;
class Score :
	public Komenda
{
public:
	Score(Gra *gra);
	~Score(void);

	void execute(ParseDTO argumenty);
	void manual();

	void wypiszStaty(Postac *posatc);
};


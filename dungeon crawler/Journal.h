#pragma once
#include "komenda.h"

class Quest;

class Journal :
	public Komenda
{
public:
	Journal(Gra *gra);
	~Journal(void);

	void execute(ParseDTO argumenty);
	void manual();
	
	void journalList();
	void journalQuestInfo(Quest *quest);
};


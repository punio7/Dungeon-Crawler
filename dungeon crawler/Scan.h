#pragma once
#include "komenda.h"
class Scan :
	public Komenda
{
public:
	Scan(Gra *gra);
	~Scan(void);

	void execute(ParseDTO argumenty);
	void manual();
	wstring celownikKierunkuSwiata(KierunekSwiata kierunek);
	void scan();
};


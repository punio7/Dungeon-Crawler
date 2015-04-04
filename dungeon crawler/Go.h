#pragma once
#include "komenda.h"
#include "kierunkiSwiata.h"

class Lokacja;

class Go :
	public Komenda
{
public:
	Go(Gra *gra);
	~Go(void);
	void execute(ParseDTO argumenty);
	void manual();

	void GoKierunek(KierunekSwiata kierunek);
	void ZmianaPolozenia(Lokacja* nowaLokacja);
};


#pragma once

#include <time.h>

class timer
{
public:
	timer(void);
	~timer(void);

	void start();
	void stop();
	int roznica();

private:
	long poczatek;
	long koniec;
};


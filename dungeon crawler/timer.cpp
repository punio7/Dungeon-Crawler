#include "timer.h"


timer::timer(void)
{
	poczatek=clock();
	koniec=clock();
}

timer::~timer(void)
{
}

void timer::start()
{
	poczatek=time(NULL);
}

void timer::stop()
{
	koniec=time(NULL);
}

int timer::roznica()
{
	return koniec-poczatek;
}

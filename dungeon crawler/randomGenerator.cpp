#include "randomGenerator.h"

int rzucaj(int max)
{
	return rand() % max + 1;
}

int rzucaj(int min, int max)
{
	return rand() % max + min;
}

void rzucajInic()
{
	srand( (unsigned)time(NULL) );
}
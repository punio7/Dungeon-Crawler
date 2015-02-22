#include "randomGenerator.h"

int rzucaj(int zakres)
{
	int i;
	i = rand() % zakres +1;
	return i;
}

void rzucajInic()
{
	srand( (unsigned)time(NULL) );
}
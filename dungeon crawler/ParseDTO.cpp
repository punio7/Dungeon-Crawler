#include "ParseDTO.h"


ParseDTO::ParseDTO(void)
{
	argument1 = "";
	argument2 = "";
	kierunek1 = KIERUNEK_NIEPOPRAWNY;
	Ekomenda komenda1 = COMM_WRONG;
	ktory1=0;
	ktory2=0;
}


ParseDTO::~ParseDTO(void)
{
}

void ParseDTO::clear()
{
	argument1 = "";
	argument2 = "";
	kierunek1 = KIERUNEK_NIEPOPRAWNY;
	Ekomenda komenda1 = COMM_WRONG;
	ktory1=0;
	ktory2=0;
}
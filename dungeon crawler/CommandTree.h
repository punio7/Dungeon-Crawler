#pragma once

#define ILOSC_ZNAKOW_W_ALFABECIE 26

#include <string>
#include "ListaKomend.h"

using namespace std;

class Command_tree
{
public:
	Ekomenda command;
	Command_tree();
	Command_tree* son[ILOSC_ZNAKOW_W_ALFABECIE];	//26-liter w alfabecie
	
};
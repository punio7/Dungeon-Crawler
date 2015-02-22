#pragma once

#include <string>
#include <iostream>
#include "Lokacja.h"
#include "command_tree.h"
#include "ParseDTO.h"

;using namespace std;

class Parser
{
public:
	Parser();
	void pobierz_linie();			//pobiera pojedyncza komende i przekazuje ja do parsuj()
	void parsuj();					//parsuje pobrana komende
	void wyciagnij_argument(int miejsce);		//z poszatkowej komendy wyjmuje argument i usadza go na miejscu i
	Ekomenda znajdz(string& command);					//znajduje komende na drzewie komend
	KierunekSwiata znajdzKierunek(string& kierunek);	//zwraca kierunek swiata ze stringu
	void oproznij_we();

	string argument1, argument2;	// argumenti- argument po sparserowaniu
	int ktory1, ktory2;			//oznacza ktory z posrod kilku elementow wskazujacych przez argumenti ma byc wybrany
	KierunekSwiata kierunek1;		//kierunek swiata wystepujacy w argumencie, np. do komendy open
	Ekomenda komenda1;				//komendy wystêpuj¹ce w argumentach, npw do komendy help
	Ekomenda komenda;			//komenda sparserowana do przyjemnej postaci
	ParseDTO argumenty;			//sparsowane argumenty
private:
	void create_command_tree();
	void create_command(char* Ccommand, Ekomenda Kcommand);
	Command_tree* komendy;
	string linia;
};
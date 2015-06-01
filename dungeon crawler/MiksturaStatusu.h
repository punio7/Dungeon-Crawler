#pragma once
#include "Item.h"

class Postac;
class Status;

class MiksturaStatusu: public Item
{
public:
	MiksturaStatusu(int id, std::wstring nazwa, std::wstring opis, std::wstring iddle, int wartosc, Status *status);
	
	bool drink(Postac *postac);
	Status *status;				//status ten potem zostaje przeniesiony do listy statusow gracza
								//jego znsizczeniem zajmuje sie klasa listy statusow
								//na jedna miksture przypada jeden obiekt statusu, dlatego mikstura
								//zawsze musi byc skasuwana aby nie doszlo do sytuacji gdzie
								//lista statusow gracza skasowala status przydzielony do jakiejs istniejacej potki
};
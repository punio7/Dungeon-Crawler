#pragma once
#include "item.h"

class Postac;
class Status;

class miksturaStatusu: public Item
{
public:
	miksturaStatusu(int id, string nazwa, string opis, string iddle, int wartosc, Status *status);
	
	bool drink(Postac *postac);
	Status *status;				//status ten potem zostaje przeniesiony do listy statusow gracza
								//jego znsizczeniem zajmuje sie klasa listy statusow
								//na jedna miksture przypada jeden obiekt statusu, dlatego mikstura
								//zawsze musi byc skasuwana aby nie doszlo do sytuacji gdzie
								//lista statusow gracza skasowala status przydzielony do jakiejs istniejacej potki
};
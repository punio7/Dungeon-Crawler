#pragma once
#include "komenda.h"
#include <array>

class Map :
	public Komenda
{
public:
	Map(Gra *gra);
	~Map(void);

	void execute(ParseDTO argumenty);
	void manual();
private:
	bool czyPoprawneWspolrzedne(int y, int x, int dlugosc, int wysokosc);
	array<int, 2> utworzWspolrzedne(int y, int x);
};


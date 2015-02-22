#include <array>
#include <list>
#include <vector>
#include "Map.h"
#include "gra.h"
#include "item.h"
#include "ListaItemow.h"
#include "lokacja.h"

Map::Map(Gra *gra):
	Komenda(gra)
{
	nazwa="map";
}


Map::~Map(void)
{
}

void Map::execute(ParseDTO argumenty)
{
	if (!gra->gracz.przedmioty->znajdz(ListaItemow::Questowe::Mapa, 1))
	{
		playerMsg("Do tego potrzebujesz mapy.");
		return;
	}
	
	const int dlugosc = 79;
	const int wysokosc = 22;
	list<Lokacja*> stosLokacji;
	list< array<int,2> > stosWspolrzednych;
	string pustyWiersz(dlugosc +1, ' ');
	pustyWiersz[dlugosc + 1] = '\n';

	vector< string > mapa(wysokosc, pustyWiersz);

	stosLokacji.push_front(gra->gracz.polozenie);
	stosWspolrzednych.push_front(utworzWspolrzedne(wysokosc/2, dlugosc/2));

	while (!stosLokacji.empty())
	{
		Lokacja* lokacja = stosLokacji.front();
		stosLokacji.pop_front();
		array<int, 2> wsp = stosWspolrzednych.front();
		stosWspolrzednych.pop_front();

		mapa[wsp[0]][wsp[1]] = 'O';
		if (lokacja == gra->gracz.polozenie)
		{
			mapa[wsp[0]][wsp[1]] = '×';
		}
		else if (lokacja->wyjscie[UP] || lokacja->wyjscie[DOWN])
		{
			mapa[wsp[0]][wsp[1]] = 'ô';
		}
		if (lokacja->wyjscie[NORTH])
		{
			if (czyPoprawneWspolrzedne(wsp[0] - 1, wsp[1], dlugosc, wysokosc))
			{
				mapa[wsp[0] - 1][wsp[1]] = '|';
				if (czyPoprawneWspolrzedne(wsp[0] - 2, wsp[1], dlugosc, wysokosc)
					&& mapa[wsp[0]-2][wsp[1]] == ' ')
				{
					stosLokacji.push_front(lokacja->wyjscie[NORTH]);
					stosWspolrzednych.push_front(utworzWspolrzedne(wsp[0] - 2, wsp[1]));
				}
			}
		}
		if (lokacja->wyjscie[SOUTH])
		{
			if (czyPoprawneWspolrzedne(wsp[0] + 1, wsp[1], dlugosc, wysokosc))
			{
				mapa[wsp[0] + 1][wsp[1]] = '|';
				if (czyPoprawneWspolrzedne(wsp[0] + 2, wsp[1], dlugosc, wysokosc)
					&& mapa[wsp[0]+2][wsp[1]] == ' ')
				{
					stosLokacji.push_front(lokacja->wyjscie[SOUTH]);
					stosWspolrzednych.push_front(utworzWspolrzedne(wsp[0] + 2, wsp[1]));
				}
			}
		}
		if (lokacja->wyjscie[WEST])
		{
			if (czyPoprawneWspolrzedne(wsp[0], wsp[1] - 1, dlugosc, wysokosc))
			{
				mapa[wsp[0]][wsp[1] - 1] = '—';
				if (czyPoprawneWspolrzedne(wsp[0], wsp[1] - 2, dlugosc, wysokosc)
					&& mapa[wsp[0]][wsp[1]-2] == ' ')
				{
					stosLokacji.push_front(lokacja->wyjscie[WEST]);
					stosWspolrzednych.push_front(utworzWspolrzedne(wsp[0], wsp[1] - 2));
				}
			}
		}
		if (lokacja->wyjscie[EAST])
		{
			if (czyPoprawneWspolrzedne(wsp[0], wsp[1] + 1, dlugosc, wysokosc))
			{
				mapa[wsp[0]][wsp[1] + 1] = '—';
				if (czyPoprawneWspolrzedne(wsp[0], wsp[1] + 2, dlugosc, wysokosc)
					&& mapa[wsp[0]][wsp[1]+2] == ' ')
				{
					stosLokacji.push_front(lokacja->wyjscie[EAST]);
					stosWspolrzednych.push_front(utworzWspolrzedne(wsp[0], wsp[1] + 2));
				}
			}
		}
	}

	for (string &wiersz : mapa)
	{
		cout << wiersz;
	}
}

bool Map::czyPoprawneWspolrzedne(int y, int x, int dlugosc, int wysokosc)
{
	if (y >= wysokosc || y < 0 || x >= dlugosc || x < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

array<int, 2> Map::utworzWspolrzedne(int y, int x)
{
	array<int, 2> temp;
	temp[0] = y;
	temp[1] = x;
	return temp;
}


void Map::manual()
{
	Komenda::manual();	//TODO wpisac manual dla danej komendy
}
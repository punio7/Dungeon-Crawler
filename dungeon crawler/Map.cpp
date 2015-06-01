#include <array>
#include <list>
#include <vector>
#include "Map.h"
#include "Gra.h"
#include "Item.h"
#include "ListaItemow.h"
#include "Lokacja.h"

Map::Map(Gra *gra):
	Komenda(gra)
{
	nazwa = L"map";
}


Map::~Map(void)
{
}

void Map::execute(ParseDTO argumenty)
{
	if (!gra->gracz.przedmioty->znajdz(ListaItemow::Questowe::Mapa, 1))
	{
		playerMsg(L"Do tego potrzebujesz mapy.");
		return;
	}
	
	const int dlugosc = 79;
	const int wysokosc = 22;
	list<Lokacja*> stosLokacji;
	list< array<int,2> > stosWspolrzednych;
	wstring pustyWiersz(dlugosc +1, ' ');
	pustyWiersz[dlugosc + 1] = '\n';

	vector< wstring > mapa(wysokosc, pustyWiersz);

	stosLokacji.push_front(gra->gracz.polozenie);
	stosWspolrzednych.push_front(utworzWspolrzedne(wysokosc/2, dlugosc/2));

	while (!stosLokacji.empty())
	{
		Lokacja* lokacja = stosLokacji.front();
		stosLokacji.pop_front();
		array<int, 2> wsp = stosWspolrzednych.front();
		stosWspolrzednych.pop_front();

		mapa[wsp[0]][wsp[1]] = L'O';
		if (lokacja == gra->gracz.polozenie)
		{
			mapa[wsp[0]][wsp[1]] = L'X';
		}
		else if (lokacja->wyjscie[UP] || lokacja->wyjscie[DOWN])
		{
			mapa[wsp[0]][wsp[1]] = L'ô';
		}
		if (lokacja->wyjscie[NORTH])
		{
			if (czyPoprawneWspolrzedne(wsp[0] - 1, wsp[1], dlugosc, wysokosc))
			{
				mapa[wsp[0] - 1][wsp[1]] = L'|';
				if (czyPoprawneWspolrzedne(wsp[0] - 2, wsp[1], dlugosc, wysokosc)
					&& mapa[wsp[0]-2][wsp[1]] == L' '
					&& lokacja->wyjscie[NORTH]->odwiedzona)
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
				mapa[wsp[0] + 1][wsp[1]] = L'|';
				if (czyPoprawneWspolrzedne(wsp[0] + 2, wsp[1], dlugosc, wysokosc)
					&& mapa[wsp[0]+2][wsp[1]] == L' '
					&& lokacja->wyjscie[SOUTH]->odwiedzona)
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
				mapa[wsp[0]][wsp[1] - 1] = L'-';
				if (czyPoprawneWspolrzedne(wsp[0], wsp[1] - 2, dlugosc, wysokosc)
					&& mapa[wsp[0]][wsp[1]-2] == ' '
					&& lokacja->wyjscie[WEST]->odwiedzona)
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
				mapa[wsp[0]][wsp[1] + 1] = L'—';
				if (czyPoprawneWspolrzedne(wsp[0], wsp[1] + 2, dlugosc, wysokosc)
					&& mapa[wsp[0]][wsp[1]+2] == L' '
					&& lokacja->wyjscie[EAST]->odwiedzona)
				{
					stosLokacji.push_front(lokacja->wyjscie[EAST]);
					stosWspolrzednych.push_front(utworzWspolrzedne(wsp[0], wsp[1] + 2));
				}
			}
		}
	}

	for (wstring &wiersz : mapa)
	{
		wcout << wiersz;
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
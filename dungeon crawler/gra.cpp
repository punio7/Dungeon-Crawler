﻿#include "Gra.h"
#include <thread>
#include <iostream>
#include <sstream>
#include <windows.h>
#include "Quest.h"
#include "zdarzeniaGlobalne.h"
#include "playerMsg.h"
#include "drukuj.h"
#include "ListaItemow.h"
#include "odpoczynek.h"
#include "Rasa.h"
#include "Klasa.h"
#include "randomGenerator.h"
#include "midi.h"
#include "Look.h"
#include "ListaKomend.h"

using namespace std;

extern Gra* instanceOfGra;

Gra::Gra(int argc, const char* argv[])
{
	wcout << L"Zaczynamy nową grę!" << endl;
	path = argv[0];
	path = path.substr(0, path.rfind('\\') + 1);	//pozbywamy sie pliku exe ze sciezki gry
	stan = STAN_GRA;

	instanceOfGra = this;
	midiPlayer = new MidiPlayer(path);
	rzucajInic();
	wczytajRasy();
	wczytajKlasy();
	gracz.tworzenie_postaci();
	listaKomend = new ListaKomend(this);
	wczytaj_lokacje();
	wczytajQuesty();
	gracz.polozenie = getLokacja(0);
	gracz.equip(createItem(ListaItemow::Magiczne::KoszulaLniana));
	gracz.equip(createItem(ListaItemow::Magiczne::SpodnieLniane));
	//gracz.dodajPrzedmiot(createItem(ListaItemow::Pojemniki::TorbaPodrozna));
	//gracz.dodajPrzedmiot(createItem(ListaItemow::Questowe::Mapa));
	//gracz.equip(createItem(ListaItemow::Pancerze::ButySkora));
	//gracz.equip(createItem(ListaItemow::Pancerze::NagolennikiSkora));
	//gracz.equip(createItem(ListaItemow::Pancerze::NaramiennikiSkora));
	//gracz.equip(createItem(ListaItemow::Pancerze::RekawiceSkora));
	//gracz.equip(createItem(ListaItemow::Pancerze::ZbrojaSkora));
	//gracz.polozenie = getLokacja(20);	//DEBUG ZMIANA POLOZENIA GRACZA
	(gracz.statusy)->dodaj(new StatusOdpoczynek());
	gracz.przelicz();
	zdarzeniaGlobalnePrzySpotkaniu();
	zdarzeniaPrzySpotkaniu();
	dynamic_cast<Look*>(listaKomend->komendy[COMM_LOOK])->LookMiejsce(gracz.polozenie);
	prompt();
	stoper.start();
}

void Gra::zakonczGre()
{
	wcout << "Cóż, więcej szczęścia następnym razem." << endl;
	stan = STAN_QUIT;
}

void Gra::prompt()
{
	playerMsg(L"\n[|0 |1/|2 |C|3exp |Y|4z³|G|5 |W|6s] |_",
		gracz.poziomZdrowia(),
		intToStr(gracz.currentHP),
		intToStr(gracz.zdr_calk),
		intToStr(gracz.exp),
		intToStr(gracz.zloto),
		gracz.pktCech > 0 ? L" +" : L"",
		intToStr(stoper.roznica()));
}

Quest* Gra::znajdzQuest(wstring nazwa, int ktory)
{
	Quest* aktualny = NULL;
	for (int i = 1; i < LICZBA_QUESTOW; i++)		//szukamy odpowiedniego zadania
	{
		if (questy[i] != NULL && (questy[i]->aktywny() || (questy[i]->zakonczony())))
		{
			if ((questy[i]->nazwa).find(nazwa) != -1)
			{
				ktory--;
				if (ktory <= 0)
				{
					aktualny = questy[i];
					break;
				}
			}
		}
	}

	return aktualny;
}

bool Gra::gra_zakoncz()
{
	if (stan == STAN_GRA) return false;
	else return true;
}
#include "Go.h"
#include "Gra.h"
#include "Lokacja.h"
#include "Look.h"
#include "ListaKomend.h"

Go::Go(Gra *gra) :
Komenda(gra)
{
	nazwa = L"";
}


Go::~Go(void)
{
}

void Go::execute(ParseDTO argumenty)
{
	if (argumenty.kierunek1 == KIERUNEK_NIEPOPRAWNY)
	{
		playerMsg(L"Mo¿e lepiej zostaæ tutaj i zjeœæ kilka pierogów?");
		return;
	}

	GoKierunek(argumenty.kierunek1);
}

void Go::GoKierunek(KierunekSwiata kierunek)
{
	Gracz &gracz = gra->gracz;
	if ((gracz.polozenie->wyjscie)[kierunek] == NULL || (gracz.polozenie->zamek)[kierunek] == -1)
	{
		playerMsg(L"Nie mo¿esz tam pójœæ.");
	}
	else
	{
		if ((gracz.polozenie->zamek)[kierunek] > 0)
		{
			playerMsg(L"Przejœcie jest zamkniête.");
		}
		else
		{
			gracz.poprzedniePolozenie = kierunekPrzeciwny(kierunek);
			ZmianaPolozenia((gracz.polozenie->wyjscie)[kierunek]);
		}
	}
}

void Go::ZmianaPolozenia(Lokacja* nowaLokacja)
{
	gra->gracz.polozenie = nowaLokacja;
	nowaLokacja->odwiedzona = true;
	if (gra->zdarzeniaGlobalnePrzySpotkaniu())	//jezeli zdarzenie zwroci true to przerywamy reszte
		return;
	dynamic_cast<Look*>(listaKomend->komendy[COMM_LOOK])->LookMiejsce(gra->gracz.polozenie);
	gra->zdarzeniaPrzySpotkaniu();
}

void Go::manual()
{
	Komenda::manual();	//brak manuala dla tej "komendy"
}

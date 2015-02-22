#include "Go.h"
#include "gra.h"
#include "Lokacja.h"
#include "Look.h"

extern ListaKomend *listaKomend;

Go::Go(Gra *gra):
	Komenda(gra)
{
	nazwa="";
}


Go::~Go(void)
{
}

void Go::execute(ParseDTO argumenty)
{
	if (argumenty.kierunek1 == KIERUNEK_NIEPOPRAWNY)
	{
		playerMsg("Mo¿e lepiej zostaæ tutaj i zjeœæ kilka pierogów?");
		return;
	}

	GoKierunek(argumenty.kierunek1);
}

void Go::GoKierunek(KierunekSwiata kierunek)
{
	Gracz &gracz = gra->gracz;
	if ((gracz.polozenie->wyjscie)[kierunek]==NULL || (gracz.polozenie->zamek)[kierunek]==-1) 
	{
		playerMsg("Nie mo¿esz tam pójœæ.");
	}
	else 
	{
		if ((gracz.polozenie->zamek)[kierunek]>0) 
		{
			playerMsg("Przejœcie jest zamkniête.");
		}
		else 
		{
			gracz.polozenie=(gracz.polozenie->wyjscie)[kierunek];
			gracz.poprzedniePolozenie = kierunekPrzeciwny(kierunek);
			if (gra->zdarzeniaGlobalnePrzySpotkaniu())	//jezeli zdarzenie zwroci true to przerywamy reszte
				return;
			dynamic_cast<Look*>(listaKomend->komendy[COMM_LOOK])->LookMiejsce(gracz.polozenie);
			gra->zdarzeniaPrzySpotkaniu();
		}
	}
}

void Go::manual()
{
	Komenda::manual();	//brak manuala dla tej "komendy"
}

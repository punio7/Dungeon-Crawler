#include "Gra.h"
#include "Lokacja.h"
#include "midi.h"
#include "Talk.h"
#include "Kill.h"
#include "ListaKomend.h"

extern ListaKomend *listaKomend;

void Gra::zdarzeniaPrzySpotkaniu()
{
	Lokacja* polozenie = gracz.polozenie;

	if (Postac* postac = (polozenie->postacie)->znajdzRozmowny() )
	{
		dynamic_cast<Talk*>(listaKomend->komendy[COMM_TALK])->talk(postac);
		postac->ustawRozmowny(false);
	}

	if (polozenie->backgroundMusic > -1)
	{
		midiPlayer->play(polozenie->backgroundMusic);
	}

	if (Postac* postac = (polozenie->postacie)->znajdzAgresywny() )
	{
		playerMsg(L"|^|0 rzuca siê na ciebie bez ostrze¿enia!", postac->imie);
		dynamic_cast<Kill*>(listaKomend->komendy[COMM_KILL])->rozpocznijWalke(postac);
	}
}

bool Gra::zdarzeniaGlobalnePrzySpotkaniu()
{
	Lokacja* polozenie = gracz.polozenie;

	if (polozenie->jednorazoweZdGlob) 
	{
		int temp = polozenie->jednorazoweZdGlob;
		polozenie->jednorazoweZdGlob = 0;
		if (zdarzenieGlobalne(temp))
			return true; //jezeli zdazenie zwrocilo true to przerywamy inne zdarzenia
	}

	if (polozenie->zdGlob)
	{
		if (zdarzenieGlobalne(polozenie->zdGlob))
			return true; //jezeli zdazenie zwrocilo true to przerywamy inne zdarzenia
	}

	return false;
}
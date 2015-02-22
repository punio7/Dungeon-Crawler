#pragma once

#define DEBUG_WALKA 0

#include <math.h>
#include <vector>

class Gracz;
class Postac;

using namespace std;

class OpisyWalki
{
public:
	OpisyWalki();
	
	vector<string> opisyGraczTrafienie;
	vector<string> opisyGraczPudlo;
	vector<string> opisyWrogTrafienie;
	vector<string> opisyWrogPudlo;
};

class Walka
{
public:
	Walka(Gracz* strona1, Postac* strona2);
	~Walka(void);

	//true jezeli ktoremus z walczacych  skonczyly sie hp
	bool koniecWalki();		
	//-1 -przegrana gracza, 1 =wygrana gracza, 0 -walka nadal trwa
	int wynikWalki();

	void kolejnaTura();
	void turaGracza();
	void turaPrzeciwnika();
	bool czyTrafienie(int rzut, int atak, int obrona);
	void zadajObrazenia(Postac &cel, double ilosc);
	void opisAtakuGracza(bool trafienie);
	void opisAtakuWroga(bool trafienie);
	void opisObrazenGracza(int ilosc, Postac* postac);
	void opisObrazenWroga(int ilosc, Postac* postac);
	void prompt();

	static OpisyWalki opisyWalki;
	int runda;
	Gracz& gracz;
	Postac& wrog;
};


#include "Walka.h"
#include "gracz.h"
#include "randomGenerator.h"
#include "Upadek.h"
#include "playerMsg.h"

OpisyWalki Walka::opisyWalki;

Walka::Walka(Gracz* strona1, Postac* strona2):
	 gracz(*strona1), wrog(*strona2)
{
	runda=1;
	gracz.statusy->dodaj(new Upadek());
	wrog.statusy->dodaj(new Upadek());
	gracz.currentPanc=gracz.panc_calk;
	wrog.currentPanc=wrog.panc_calk;
}

Walka::~Walka(void)
{
}

void Walka::kolejnaTura()
{
	if (DEBUG_WALKA)
		playerMsg(L"Runda |0", intToStr(runda));
	gracz.aktywujStatusyWalka(wrog);
	gracz.przelicz();
	wrog.aktywujStatusyWalka(gracz);
	wrog.przelicz();
	turaGracza();
	turaPrzeciwnika();
	gracz.usunNieatywneStatusy();
	wrog.usunNieatywneStatusy();
	runda++;
	prompt();
}

bool Walka::koniecWalki()
{
	if ( gracz.currentHP<=0 || wrog.currentHP<=0 ) return true;
	else return false;
}

int Walka::wynikWalki()
{
	if ( gracz.currentHP <=0 ) return -1;
	if ( wrog.currentHP <=0 ) return 1;
	return 0;
}

void Walka::turaGracza()
{
	int rzut=rzucaj(100);

	if ( rzut>5 && ( czyTrafienie(rzut, gracz.at_calk, wrog.obr_calk) || rzut>95 ) )
	{
		
		if (DEBUG_WALKA)
		{
			playerMsg(L"|GWyrzuci�e� |0 atak |1 przeciwko |2. Trafienie!",
				intToStr(rzut), 
				floatToStr(((float)rzut/100)*(gracz.at_calk)),
				floatToStr((float)wrog.obr_calk/2));
		}
		else opisAtakuGracza(true);

		rzut = (rzucaj(31) -16);
		double bonusDmg = 0;
		bonusDmg = ((double)rzut/100) * gracz.dmg_calk;

		if ( (gracz.dmg_calk + bonusDmg) <= 0) 
			bonusDmg = 1 - gracz.dmg_calk;	//gracz zawsze zada przynajmniej 1 dmg

		zadajObrazenia(wrog, gracz.dmg_calk + bonusDmg);

	}
	else
	{
		
		if (DEBUG_WALKA) 
		{
			playerMsg(L"|sWyrzuci�e� |0 atak |1 przeciwko |2. Pud�o!",
				intToStr(rzut), 
				floatToStr(((float)rzut/100)*(gracz.at_calk)),
				floatToStr((float)wrog.obr_calk/2));
		}
		else opisAtakuGracza(false);

	}
}

void Walka::turaPrzeciwnika()
{
	int rzut=rzucaj(100);
	
	if ( rzut>5 && ( czyTrafienie(rzut, wrog.at_calk, gracz.obr_calk) || rzut>95 ) )
	{
		
		if (DEBUG_WALKA)
		{
			playerMsg(L"|RWr�g wyrzuci� |0 atak |1 przeciwko |2. Trafienie!", 
				intToStr(rzut), 
				floatToStr(((float)rzut/100)*(wrog.at_calk)),
				floatToStr((float)gracz.obr_calk/2));
		}
		else 
			opisAtakuWroga(true);

		rzut = (rzucaj(31) -16);
		double bonusDmg=0;
		bonusDmg = ((float)rzut/100) * gracz.dmg_calk;

		if ( (wrog.dmg_calk + bonusDmg) <= 0) 
			bonusDmg = 1 - wrog.dmg_calk;	//wr�g zawsze zada przynajmniej 1 dmg
		
		zadajObrazenia(gracz, (wrog.dmg_calk + bonusDmg));
	}
	else
	{
		if (DEBUG_WALKA) 
		{
			playerMsg(L"|sWr�g wyrzuci� |0 atak |1 przeciwko |2. Pud�o!", 
				intToStr(rzut), 
				floatToStr(((float)rzut/100)*(wrog.at_calk)),
				floatToStr((float)gracz.obr_calk/2));
		}
		else opisAtakuWroga(false);
	}
}

bool Walka::czyTrafienie(int rzut, int atak, int obrona)
{
	return ((float)rzut/100)*atak >= (float)obrona/2;
}

void Walka::zadajObrazenia(Postac &cel, double ilosc)
{
	ilosc = floor((ilosc * cel.otrzymywaneObrazenia) + 0.5 );

	if (DEBUG_WALKA)
	{
		if (cel.jestGraczem())
		{
			playerMsg(L"|RWr�g zadaje ci |0 obra�e�. |_", intToStr(ilosc));
		}
		else
		{
			playerMsg(L"|GZadajesz wrogowi |0 obra�e�. |_", intToStr(ilosc));
		}
	}
	
	if (cel.currentPanc > 0)
	{
		int dmg= floor( ((float)cel.ochr_calk/600) * ilosc);
		if ( (dmg<=0) && ilosc>1 ) dmg=1;	//pancerz zawsze blokuje 1 punkt obra�e�, chyba �e ca�o�� to 1 pkt
		if (dmg >= cel.currentPanc)
		{
			if (DEBUG_WALKA) 
				playerMsg(L"Pancerz poch�on�� |0 obra�e�.", intToStr(cel.currentPanc));
			else
			{
				cel.jestGraczem() ? playerMsg(L"Wr�g przebi� tw�j pancerz!") : playerMsg(L"Uda�o ci si� przebi� wrogi pancerz!");
				cel.jestGraczem() ? opisObrazenGracza(ilosc, &cel) : opisObrazenWroga(ilosc, &cel);
			}
			ilosc -= cel.currentPanc;
			cel.currentPanc = 0;
			cel.currentHP -= ilosc;
		}
		else
		{
			if (DEBUG_WALKA) 
				playerMsg(L"Pancerz poch�on�� |0 obra�e�.", intToStr(dmg));
			else
				cel.jestGraczem() ? opisObrazenGracza(ilosc-dmg, &cel) : opisObrazenWroga(ilosc-dmg, &cel);
			cel.currentPanc -= dmg;
			cel.currentHP -= (ilosc-dmg);
		}
	}
	else
	{
		if (DEBUG_WALKA) 
			playerMsg(L"Pancerz poch�on�� 0 obra�e�.");
		else
			cel.jestGraczem() ? opisObrazenGracza(ilosc, &cel) : opisObrazenWroga(ilosc, &cel);
		cel.currentHP -= ilosc;
	}
}

void Walka::opisAtakuGracza(bool trafienie)
{
	if (trafienie)
	{
		int opcja = rzucaj(opisyWalki.opisyGraczTrafienie.size());
		playerMsg(L"|G|0", opisyWalki.opisyGraczTrafienie[opcja-1]);
	}
	else
	{
		int opcja = rzucaj(opisyWalki.opisyGraczPudlo.size());
		playerMsg(L"|s|0", opisyWalki.opisyGraczPudlo[opcja-1]);
	}
}

void Walka::opisAtakuWroga(bool trafienie)
{
	if (trafienie)
	{
		int opcja = rzucaj(opisyWalki.opisyWrogTrafienie.size());
		playerMsg(L"|R|0", opisyWalki.opisyWrogTrafienie[opcja-1]);
	}
	else
	{
		int opcja = rzucaj(opisyWalki.opisyWrogPudlo.size());
		playerMsg(L"|s|0", opisyWalki.opisyWrogPudlo[opcja-1]);
	}
}

void Walka::opisObrazenGracza(int ilosc, Postac *postac)
{
	int procent = (float)ilosc / postac->zdr_calk * 100;

	if (procent < 5 )
	{
		playerMsg(L"|RCios przeciwnika ledwie ci� zadrapa�.");
	}
	else if (procent < 10) 
	{
		playerMsg(L"|RCios przeciwnika lekko ci� zrani�.");
	}
	else if (procent <15)
	{
		playerMsg(L"|RCios przeciwnika powa�nie ci� zrani�.");
	}
	else
	{
		playerMsg(L"|RCios przeciwnika bardzo powa�nie ci� zrani�.");
	}
}

void Walka::opisObrazenWroga(int ilosc, Postac *postac)
{
	int procent = (float)ilosc / postac->zdr_calk * 100;

	if (procent < 5 )
	{
		playerMsg(L"|GTw�j cios ledwie zadrapa� przeciwnika.");
	}
	else if (procent < 10) 
	{
		playerMsg(L"|GTw�j cios lekko zrani� przeciwnika.");
	}
	else if (procent <15)
	{
		playerMsg(L"|GTw�j cios powa�nie zrani� przeciwnika.");
	}
	else
	{
		playerMsg(L"|GTw�j cios bardzo pwoa�nie zrani� przeciwnika.");
	}
}

void Walka::prompt()
{
	if (!DEBUG_WALKA)
		playerMsg(L"\n[|0: |1 |2: |3]", gracz.imie, gracz.poziomZdrowia(), wrog.imie, wrog.poziomZdrowia());
	else
	{
		playerMsg(L"\n[|0: |1 |2/|3 |4/|5|_",
		gracz.imie, gracz.poziomZdrowia(),
		intToStr(gracz.currentHP), intToStr(gracz.zdr_calk), intToStr(gracz.currentPanc), intToStr(gracz.panc_calk) );
		playerMsg(L"|0: |1 |2/|3 |4/|5]",
		wrog.imie, wrog.poziomZdrowia(),
		intToStr(wrog.currentHP), intToStr(wrog.zdr_calk), intToStr(wrog.currentPanc), intToStr(wrog.panc_calk) );
	}
}
#include "postac.h"
#include "item.h"
#include "status.h"
#include "playerMsg.h"
#include "Rozmowa.h"


CharList::CharList()
{

}

CharList::~CharList()
{

}

wstring CharList::wypisz(CharListWypiszTryb tryb)
{
	if (empty())
	{
		if (tryb == CHARLIST_WYPISZ_SCAN)
			return L"\t|gnikogo nie ma.";
	}


	wstring temp;
	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if (tryb == CHARLIST_WYPISZ_SCAN)
			temp += L"\t|C";
		temp += (*aktualny)->imie;
		if (tryb == CHARLIST_WYPISZ_LOOK)
		{
			temp += ' ';
			temp += (*aktualny)->idle;	//idle dodajemy tylko w look
		}
		temp += '\n';
	}

	return temp;
}

void CharList::dodaj(Postac *przedmiot)
{
	push_back(przedmiot);
}

void CharList::usun(Postac *postac)
{
	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if (*aktualny == postac)
		{
			erase(aktualny);
			break;
		}
	}
}

Postac* CharList::znajdz(wstring szukany, int ktory)
{
	if (empty()) return NULL;	//jeżeli lista pusta to i tak nic nie znajdziemy

	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if ((((*aktualny)->imie).find(szukany)) != -1)
		{
			if (ktory < 2) return *aktualny;
			else ktory--;
		}
	}

	return NULL;	//jeżeli przeszukano całą listę i nic nie znaleziono
}

Postac* CharList::znajdz(int id, int ktory)
{
	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if ((*aktualny)->id == id)
		{
			if (ktory < 2) return *aktualny;
			else ktory--;
		}
	}

	return NULL;
}

Postac* CharList::znajdzAgresywny(int ktory)
{
	if (empty()) return NULL;	//jeżeli lista pusta to i tak nic nie znajdziemy

	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if ((*aktualny)->agresywny)
		{
			if (ktory < 2) return *aktualny;
			else ktory--;
		}
	}

	return NULL;	//jeżeli przeszukano całą listę i nic nie znaleziono
}

Postac* CharList::znajdzRozmowny(int ktory)
{
	if (empty()) return NULL;	//jeżeli lista pusta to i tak nic nie znajdziemy

	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if ((*aktualny)->jestRozmowny())
		{
			if (ktory < 2) return *aktualny;
			else ktory--;
		}
	}

	return NULL;	//jeżeli przeszukano całą listę i nic nie znaleziono
}

Postac* CharList::znajdzTrener(int ktory)
{
	if (empty()) return NULL;	//jeżeli lista pusta to i tak nic nie znajdziemy

	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if ((*aktualny)->jestTrenerem())
		{
			if (ktory < 2) return *aktualny;
			else ktory--;
		}
	}

	return NULL;	//jeżeli przeszukano całą listę i nic nie znaleziono
}

Postac* CharList::znajdzKupiec(int ktory)
{
	if (empty()) return NULL;	//jeżeli lista pusta to i tak nic nie znajdziemy

	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if ((*aktualny)->jestKupcem())
		{
			if (ktory < 2) return *aktualny;
			else ktory--;
		}
	}

	return NULL;	//jeżeli przeszukano całą listę i nic nie znaleziono
}

bool CharList::pusta()
{
	return empty();
}



Postac::Postac()
{
	id = 0;
	poziom = 0;
	dawaneDoswiadczenie = 0;
	currentHP = 0;
	agresywny = false;
	quest = 0; questFaza = 0;

	rasa = getRasa(RASA_BRAK);
	klasa = getKlasa(KLASA_BRAK);

	sil_baz = 0, zr_baz = 0, zw_baz = 0, wyt_baz = 0, zyw_baz = 0;
	sil_bon = 0, zr_bon = 0, zw_bon = 0, wyt_bon = 0, zyw_bon = 0;
	sil_calk = 0, zr_calk = 0, zw_calk = 0, wyt_calk = 0, zyw_baz = 0;
	at_cecha = 0, obr_cecha = 0, zdr_cecha = 0, panc_cecha = 0, zm_cecha = 0, dmg = 0;
	at_poz = 0, obr_poz = 0, zdr_poz = 0, zm_poz = 0;
	at_eq = 0, obr_eq = 0, zdr_eq = 0, panc_eq = 0, ochr_eq = 0, zm_eq = 0, dmg_eq = 0;
	at_bon = 0, obr_bon = 0, zdr_bon = 0, panc_bon = 0, ochr_bon = 0, zm_bon = 0, dmg_bon = 0;
	at_mod = 0, obr_mod = 0, zdr_mod = 0, panc_mod = 0, ochr_mod = 0, zm_mod = 0, dmg_mod = 0;
	at_calk = 0, obr_calk = 0, zdr_calk = 0, panc_calk = 0, ochr_calk = 0, zm_calk = 0, dmg_calk = 0;


	for (int i = 0; i < SLOT_ILOSC; i++)
	{
		eq[i] = NULL;
	}
	zloto = 0;
	przedmioty = new ItemList;
	statusy = new StatusList;
}

Postac::~Postac()
{
	delete przedmioty;
}

void Postac::przelicz()
{
	sil_bon = 0, zr_bon = 0, zw_bon = 0, wyt_bon = 0, zyw_bon = 0;
	at_bon = 0, obr_bon = 0, zdr_bon = 0, panc_bon = 0, ochr_bon = 0, zm_bon = 0, dmg_bon = 0;
	at_mod = 0, obr_mod = 0, zdr_mod = 0, panc_mod = 0, ochr_mod = 0, zm_mod = 0, dmg_mod = 0;

	otrzymywaneObrazenia = 1.00;
	maksymalneObrazenia = false;

	aktywujStatusyPasywne();

	//CECHY

	//cechy bazowe
	sil_calk = sil_baz;
	zr_calk = zr_baz;
	zw_calk = zw_baz;
	wyt_calk = wyt_baz;
	zyw_calk = zyw_baz;

	//bonusy za umagicznienia ekwipunku

	//bonusy za rasę i klasę
	sil_calk += (int)floor(((float)sil_baz)*(rasa->si + klasa->getSi(poziom)) + 0.5);	//+0.5 dla zaokrąglenia matematycznego
	zr_calk += (int)floor(((float)zr_baz)*(rasa->zr + klasa->getZr(poziom)) + 0.5);
	zw_calk += (int)floor(((float)zw_baz)*(rasa->zw + klasa->getZw(poziom)) + 0.5);
	wyt_calk += (int)floor(((float)wyt_baz)*(rasa->wyt + klasa->getWyt(poziom)) + 0.5);
	zyw_calk += (int)floor(((float)zyw_baz)*(rasa->zyw + klasa->getZyw(poziom)) + 0.5);

	//bonusy za profity

	//inne bonusy
	sil_calk += sil_bon;
	zr_calk += zr_bon;
	zw_calk += zw_bon;
	wyt_calk += wyt_bon;
	zyw_calk += zyw_bon;


	//ATRYBUTY

	//za ekwipunek
	przelicz_eq();

	//podstawa z cech
	at_cecha = (int)((1.5*(float)zr_calk) + (0.25*(float)zw_calk));
	obr_cecha = (int)((1.5*(float)zw_calk) + (0.25*(float)zr_calk));
	zdr_cecha = (int)((2 * (float)zyw_calk) + (0.5*(float)wyt_calk));
	panc_cecha = wyt_calk;
	zm_cecha = (int)floor(20 + (0.045*(float)wyt_calk) + (0.04*(float)zyw_calk) + 0.5);
	dmg = (int)((pow((float)(poziom + sil_calk), 0.9f))*1.2);

	//za poziom
	at_poz = (int)(3 * poziom);
	obr_poz = (int)(3 * poziom);
	zdr_poz = (int)(4 * poziom);
	zm_poz = (int)(0.1*poziom);

	//suma
	at_calk = at_cecha + at_poz + at_eq + at_bon;
	obr_calk = obr_cecha + obr_poz + obr_eq + obr_bon;
	zdr_calk = zdr_cecha + zdr_poz + zdr_eq + zdr_bon;
	panc_calk = panc_cecha + panc_eq + panc_bon;
	ochr_calk = ochr_eq + ochr_bon;
	zm_calk = zm_cecha + zm_poz + zm_eq + zm_bon;
	dmg_calk = (int)floor(dmg_eq*(1 + ((float)(dmg + dmg_bon) / 100)));

	//modyfikatory
	at_calk *= (1 + ((float)at_mod / 100));
	obr_calk *= (1 + ((float)obr_mod / 100));
	zdr_calk *= (1 + ((float)zdr_mod / 100));
	panc_calk *= (1 + ((float)panc_mod / 100));
	ochr_calk *= (1 + ((float)ochr_mod / 100));
	zm_calk *= (1 + ((float)zm_mod / 100));
	dmg_calk *= (1 + ((float)dmg_mod / 100));
}

void Postac::wypisz_staty()
{
	wcout << "Wojownik L" << imie << " L" << rasa->nazwa << L" L" << klasa->nazwa << " poziomu L" << poziom << endl << endl;

	color(BLUE);
	wcout << "Cecha\t\tBazowa\tRasowy\tKlasowy\tBonusy\tLaczna" << endl;
	wcout << "Sila\t\t" << sil_baz << "\t" << rasa->si << "%\t" << klasa->getSi(poziom) << "%\t" << sil_bon << "\t" << sil_calk << endl;
	wcout << "Zrecznosc\t" << zr_baz << "\t" << rasa->zr << "%\t" << klasa->getZr(poziom) << "%\t" << zr_bon << "\t" << zr_calk << endl;
	wcout << "Zwinnosc\t" << zw_baz << "\t" << rasa->zw << "%\t" << klasa->getZw(poziom) << "%\t" << zw_bon << "\t" << zw_calk << endl;
	wcout << "Wytrzymalosc\t" << wyt_baz << "\t" << rasa->wyt << "%\t" << klasa->getWyt(poziom) << "%\t" << wyt_bon << "\t" << wyt_calk << endl;
	wcout << "Zywotnosc\t" << zyw_baz << "\t" << rasa->zyw << "%\t" << klasa->getZyw(poziom) << "%\t" << zyw_bon << "\t" << zyw_calk << endl << endl;

	color(HBLUE);
	wcout << "Atrybut\t\tCecha\tPoziom\tSprzet\tBonusy\tModyf.\tRazem" << endl;
	wcout << "Atak\t\t" << at_cecha << "\t" << at_poz << "\t" << at_eq << "\t" << at_bon << "\t+" << at_mod << "%\t" << at_calk << endl;
	wcout << "Obrona\t\t" << obr_cecha << "\t" << obr_poz << "\t" << obr_eq << "\t" << obr_bon << "\t+" << obr_mod << "%\t" << obr_calk << endl;
	wcout << "Zdrowie\t\t" << zdr_cecha << "\t" << zdr_poz << "\t" << zdr_eq << "\t" << zdr_bon << "\t+" << zdr_mod << "%\t" << zdr_calk << endl;
	wcout << "Pancerz\t\t" << panc_cecha << "\t\t" << panc_eq << "\t" << panc_bon << "\t+" << panc_mod << "%\t" << panc_calk << "\t" << ochr_calk / 6 << '%' << endl;
	wcout << "Zmeczenie\t" << zm_cecha << "\t" << zm_poz << "\t" << zm_eq << "\t" << zm_bon << "\t+" << zm_mod << "%\t" << zm_calk << endl;
	wcout << "Obrazenia\t" << dmg << "\t\t" << dmg_eq << "\t" << dmg_bon << "\t+" << dmg_mod << "%\t" << dmg_calk << endl << endl;

	color(HWHITE);
}

void Postac::przelicz_eq()
{
	at_eq = 0, obr_eq = 0, zdr_eq = 0, panc_eq = 0, ochr_eq = 0, zm_eq = 0, dmg_eq = 0;

	for (int i = 0; i < SLOT_ILOSC; i++)
	{
		if (eq[i]) dodaj_staty(eq[i]->czytaj_staty());
	}
}

void Postac::equip(Item* przedmiot)
{
	ItemSlot slot = przedmiot->getSlot();
	if (slot == -1 || slot >= SLOT_ILOSC)
	{
		color(HRED);
		wcout << "Nielegelna próba wyekwpipowania przedmiotu L" << przedmiot->nazwa << " typ: L" << przedmiot->typ << endl;
		color(HWHITE);
		return;
	}
	eq[slot] = przedmiot;

	przelicz();
}

void Postac::dodajPrzedmiot(Item* przedmiot)
{
	if (!przedmiot) return;
	przedmioty->dodaj(przedmiot);
}

void Postac::usunPrzedmiot(Item* przedmiot)
{
	przedmioty->usun(przedmiot);
}

Item* Postac::znajdzPrzedmiot(int id)
{
	return przedmioty->znajdz(id, 1);
}

void Postac::dodajZloto(int ile)
{
	zloto += ile;
}

void Postac::usunZloto(int ile)
{
	if ((zloto -= ile) < 0) zloto = 0;
}

void Postac::deequipALL()
{
	for (int i = 0; i < SLOT_ILOSC; i++)
	{
		if (eq[i])
		{
			przedmioty->dodaj(eq[i]);
			eq[i] = NULL;
		}
	}
	przelicz_eq();
}


void Postac::ustawStatyBazowe(int sil, int zr, int zw, int wyt, int zyw)
{
	sil_baz = sil;
	zr_baz = zr;
	zw_baz = zw;
	wyt_baz = wyt;
	zyw_baz = zyw;
}

ItemSlot Postac::znajdzEQ(wstring szukany, int ktory)
{
	for (int i = 0; i < SLOT_ILOSC; i++)
	{
		if (eq[i])
		{
			if (((eq[i]->nazwa).find(szukany)) != -1)
			{
				if (ktory < 2) return (ItemSlot)i;
				else ktory--;
			}
		}
	}

	return (ItemSlot)-1;
}

void Postac::dodaj_staty(Staty staty)
{
	at_eq += (int)(zr_calk >= staty.zr ? staty.atak : (float)zr_calk / staty.zr * staty.atak);
	obr_eq += (int)(zw_calk >= staty.zw ? staty.obrona : (float)zw_calk / staty.zw * staty.obrona);
	zdr_eq += (int)(zyw_calk >= staty.zyw ? staty.hp : (float)zyw_calk / staty.zyw * staty.hp);
	panc_eq += (int)(wyt_calk >= staty.wyt ? staty.pancerz : (float)wyt_calk / staty.wyt * staty.pancerz);
	ochr_eq += (int)staty.ochrona;
	zm_eq += staty.cw;
	dmg_eq += (int)(sil_calk >= staty.sil ? staty.dmg : (float)sil_calk / staty.sil * staty.dmg);

}

void Postac::odejmij_staty(Staty staty)
{

}

Cecha Postac::najwyzszaCecha(int n)
{
	if (n > 5) return SILA;
	Cecha cechy[5] = { SILA, ZRECZNOSC, ZWINNOSC, WYTRZYMALOSC, ZYWOTNOSC };
	int *wartosci[5] = { &sil_calk, &zr_calk, &zw_calk, &wyt_calk, &zyw_calk };

	for (int i = 4; i > 0; i--)	//sortowanie bąbelkowe
	{
		for (int j = 0; j < i; j++)
		{
			if (*(wartosci[j]) < *(wartosci[j + 1]))
			{
				Cecha tempC = cechy[j];
				cechy[j] = cechy[j + 1];
				cechy[j + 1] = tempC;
				int *tempI = wartosci[j];
				wartosci[j] = wartosci[j + 1];
				wartosci[j + 1] = tempI;
			}
		}
	}

	return cechy[n];
}

wstring Postac::cechaTowstring(Cecha cecha)
{
	if (cecha == SILA)
	{
		return L"siła";
	}
	else if (cecha == ZRECZNOSC)
	{
		return L"zręczność";
	}
	else if (cecha == ZWINNOSC)
	{
		return L"zwinność";
	}
	else if (cecha == WYTRZYMALOSC)
	{
		return L"wytrzymałość";
	}
	else if (cecha == ZYWOTNOSC)
	{
		return L"żywotność";
	}
	else
	{
		return L"";
	}
}

bool Postac::chceRozmawiac()
{
	return false;
}

bool Postac::jestRozmowny()
{
	return false;
}

bool Postac::jestTrenerem()
{
	return false;
}

bool Postac::jestKupcem()
{
	return false;
}

bool Postac::jestGraczem()
{
	return false;
}

wstring Postac::list()
{
	return L"";
}

void Postac::setSklep(Item *sklep)
{

}

void Postac::sklepSprzedaj(Item *item, int cena)
{

}

void Postac::sklepKup(Item *item, int cena)
{

}

Item* Postac::sklepZnajdz(wstring cel, int ktory)
{
	return NULL;
}

int Postac::trener(Cecha cecha)
{
	return 0;
}

void Postac::ustawRozmowny(bool cel)
{

}

wstring Postac::poziomZdrowia(int tryb)
{
	int procent;

	procent = (int)floor((float)(currentHP * 100) / zdr_calk);

	if (procent >= 100)
	{
		switch (tryb)
		{
		case 0:
			return L"|G█████|W";
			break;
		case 1:
			return L"|Gw pełni zdrowia|W";
			break;
		default:
			break;
		}
	}

	if (procent >= 81)
	{
		switch (tryb)
		{
		case 0:
			return L"|g█████|W";
			break;
		case 1:
			return L"|glekko ranny|W";
			break;
		default:
			break;
		}
	}

	if (procent >= 61)
	{
		switch (tryb)
		{
		case 0:
			return L"|Y████░|W";
			break;
		case 1:
			return L"|Yśrednio ranny|W";
			break;
		default:
			break;
		}
	}

	if (procent >= 41)
	{
		switch (tryb)
		{
		case 0:
			return L"|y███░░|W";
			break;
		case 1:
			return L"|Ypoważnie ranny|W";
			break;
		default:
			break;
		}
	}

	if (procent >= 21)
	{
		switch (tryb)
		{
		case 0:
			return L"|R██░░░|W";
			break;
		case 1:
			return L"|Rciężko śmierci|W";
			break;
		default:
			break;
		}
	}

	if (procent >= 1)
	{
		switch (tryb)
		{
		case 0:
			return L"|R█░░░░|W";
			break;
		case 1:
			return L"|Rbliski śmierci|W";
			break;
		default:
			break;
		}
	}

	if (procent < 1)
	{
		switch (tryb)
		{
		case 0:
			return L"|R░░░░░|W";
			break;
		case 1:
			return L"|Rmartwy|W";
			break;
		default:
			break;
		}
	}

	return L"";
}

void Postac::look()
{
	wcout << opis << endl;
}

wstring Postac::wypiszEQ()
{
	wstring temp;
	temp += L"|^";
	temp += imie;
	temp += L" obecnie używa:\n";
	bool wypisanoCokolwiek = false;

	for (int i = 0; i < SLOT_ILOSC; i++)
	{
		if (eq[i])
		{
			temp += '\t';
			temp += eq[i]->nazwa;
			temp += '\n';
			wypisanoCokolwiek = true;
		}
	}

	if (!wypisanoCokolwiek)
		temp += L"Ogólnie nic.";

	return temp;
}

Rozmowa* Postac::wskRozmowa()
{
	return NULL;
}

Kwestia* Postac::wskObecnaKwestia()
{
	return NULL;
}

void Postac::aktywujStatusyPasywne()
{
	//if (!statusy->pusta())
	//{
	//	for (StatusList::iterator aktualny; aktualny = statusy->begin; aktualny++)
	//	{
	//		(*aktualny)->aktywujPasyw(this);
	//	}
	//}
	for (Status* aktualny : *statusy)
	{
		aktualny->aktywujPasyw(this);
	}
}

void Postac::aktywujStatusyWalka(Postac &wrog)
{
	//if (!statusy->pusta())
	//{
	//	for (StatusList::iterator aktualny; aktualny = statusy->begin; aktualny++)
	//	{
	//		(*aktualny)->aktywujWalka(walka, *this);
	//	}
	//}
	for (Status* aktualny : *statusy)
	{
		aktualny->aktywujWalka(*this, wrog);
	}
}

void Postac::usunNieatywneStatusy()
{
	if (statusy->pusta()) return;

	for (StatusList::iterator aktualny = statusy->begin(); aktualny != statusy->end();)
	{
		if (!(*aktualny)->isActive())
		{
			if (this->jestGraczem())
			{
				playerMsg(L"|C|0", (*aktualny)->exitMsg);
			}
			delete (*aktualny);
			aktualny = statusy->erase(aktualny);
		}
		else
		{
			aktualny++;
		}
	}

	przelicz();
}

void Postac::usunStatusyBitewne()
{
	if (statusy->pusta()) return;

	for (StatusList::iterator aktualny = statusy->begin(); aktualny != statusy->end();)
	{
		if ((*aktualny)->isBattleOnly())
		{
			delete (*aktualny);
			aktualny = statusy->erase(aktualny);
		}
		else
		{
			aktualny++;
		}

	}
	przelicz();
}
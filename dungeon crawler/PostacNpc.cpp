#include "PostacNpc.h"
#include "item.h"
#include "playerMsg.h"
#include "Rozmowa.h"

PostacNpc::PostacNpc(void)
{
	rozmowny=false;
	sklep=NULL;

	for (int i=0; i<5; i++)
	{
		trening[i] = 0;
	}
}


PostacNpc::~PostacNpc(void)
{
}

Rozmowa* PostacNpc::wskRozmowa()
{
	return rozmowa;
}

Kwestia* PostacNpc::wskObecnaKwestia()
{
	return rozmowa->znajdzObecnaKwestia();
}

bool PostacNpc::chceRozmawiac()
{
	return true;
}

bool PostacNpc::jestRozmowny()
{
	return rozmowny;
}

bool PostacNpc::jestTrenerem()
{
	for (int i=0; i<5; i++)
	{
		if (trening[i]) return true;
	}
	
	return false;
}

bool PostacNpc::jestKupcem()
{
	if (sklep != NULL) return true;
	else return false;
}

string PostacNpc::list()
{
	string tmp;
	if (sklep==NULL) return "";
	ItemList *lista = sklep->getItemList();
	if (lista == NULL || lista->pusta())
	{
		tmp += "|^" + imie +  "obecnie nie oferuje nic na sprzeda¿.";
		return tmp;
	}
	tmp += "|^" + imie + " obecnie oferuje nastepujace przedmioty:\n";
	tmp += "|YZ³oto: " + intToStr(zloto) + "z³.|W\n";

	tmp += "#\tcena\tnazwa\n";
	tmp +="~~~~~~~~~~~~~~~~~~~~~~~~\n";
	string dump;
	lista->wypisz(dump, WYPISZ_SKLEP);
	tmp += dump;
	return tmp;
}

void PostacNpc::setSklep(Item *sklep)
{
	if (sklep == NULL) return;
	if (!sklep->jestPojemnikiem()) return;

	this->sklep=sklep;
}

void PostacNpc::sklepSprzedaj(Item *item, int cena)
{
	if (sklep==NULL) return;
	if (item==NULL) return;
	ItemList *lista = sklep->getItemList();
	if (lista == NULL) return;

	lista->usun(item);
	zloto+=cena;
}

void PostacNpc::sklepKup(Item *item, int cena)
{
	if (sklep==NULL) return;
	if (item==NULL) return;
	ItemList *lista = sklep->getItemList();
	if (lista == NULL) return;

	lista->dodaj(item);
	zloto-=cena;
}

Item* PostacNpc::sklepZnajdz(string cel, int ktory)
{
	return sklep->lista_znajdz(cel, ktory);
}


int PostacNpc::trener(Cecha cecha)
{
	return trening[cecha];
}

void PostacNpc::ustawRozmowny(bool cel)
{
	rozmowny = cel;
}

void PostacNpc::dodajKwestie(Kwestia* kwestia)
{
	rozmowa->dodajKwestie(kwestia);
}
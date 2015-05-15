#include "Equipment.h"
#include "gra.h"
#include "item.h"

Equipment::Equipment(Gra *gra):
	Komenda(gra)
{
	nazwa = L"equipment";
}


Equipment::~Equipment(void)
{
}

void Equipment::execute(ParseDTO argumenty)
{
	equipment();
}

void Equipment::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   equipment(eq)\n\n"
			 L"U�ycia:\n\n"
			 L"   equipment - wy�wietla wyposa�enie u�ywane przez gracza.\n\n"
			 L"Sprawd� r�wnie�:\n"
			 L"   inventory, wear, wield, hold, remove");
}

void Equipment::equipment()
{
	auto eq = gra->gracz.eq;
	
	playerMsg(L"Obecnie u�ywasz:\n");
	
	playerMsg(L"ochrona torsu:\t|_");
	if(eq[SLOT_ZBROJA]) playerMsg(eq[SLOT_ZBROJA]->nazwa); else playerMsg(L"Nic");
	playerMsg(L"ochrona ramion:\t|_");
	if(eq[SLOT_NARAMIENNIKI]) playerMsg(eq[SLOT_NARAMIENNIKI]->nazwa); else playerMsg(L"Nic");
	playerMsg(L"ochrona d�oni:\t|_");
	if(eq[SLOT_REKAWICE]) playerMsg(eq[SLOT_REKAWICE]->nazwa); else playerMsg(L"Nic");
	playerMsg(L"ochrona n�g:|_\t|_");
	if(eq[SLOT_NAGOLENNIKI]) playerMsg(eq[SLOT_NAGOLENNIKI]->nazwa); else playerMsg(L"Nic");
	playerMsg(L"ochrona st�p:\t|_");
	if(eq[SLOT_BUTY]) playerMsg(eq[SLOT_BUTY]->nazwa); else playerMsg(L"Nic");
	playerMsg(L"ochrona g�owy:\t|_");
	if(eq[SLOT_HELM]) playerMsg(eq[SLOT_HELM]->nazwa); else playerMsg(L"Nic");
	playerMsg(L"w prawej r�ce:\t|_");
	if(eq[SLOT_PREKA]) playerMsg(eq[SLOT_PREKA]->nazwa); else playerMsg(L"Nic");
	playerMsg(L"w lewej r�ce: \t|_");
	if(eq[SLOT_LREKA]) playerMsg(eq[SLOT_LREKA]->nazwa); else playerMsg(L"Nic");
}
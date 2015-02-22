#include "Equipment.h"
#include "gra.h"
#include "item.h"

Equipment::Equipment(Gra *gra):
	Komenda(gra)
{
	nazwa="equipment";
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
	playerMsg("Synonimy:\n"
				"   equipment(eq)\n\n"
				"U¿ycia:\n\n"
				"   equipment - wyœwietla wyposa¿enie u¿ywane przez gracza.\n\n"
				"SprawdŸ równie¿:\n"
				"   inventory, wear, wield, hold, remove");
}

void Equipment::equipment()
{
	Item **eq = gra->gracz.eq;
	
	playerMsg("Obecnie u¿ywasz:\n");
	
	playerMsg("ochrona torsu:\t|_");
	if(eq[SLOT_ZBROJA]) playerMsg(eq[SLOT_ZBROJA]->nazwa); else playerMsg("Nic");
	playerMsg("ochrona ramion:\t|_");
	if(eq[SLOT_NARAMIENNIKI]) playerMsg(eq[SLOT_NARAMIENNIKI]->nazwa); else playerMsg("Nic");
	playerMsg("ochrona d³oni:\t|_");
	if(eq[SLOT_REKAWICE]) playerMsg(eq[SLOT_REKAWICE]->nazwa); else playerMsg("Nic");
	playerMsg("ochrona nóg:|_\t|_");
	if(eq[SLOT_NAGOLENNIKI]) playerMsg(eq[SLOT_NAGOLENNIKI]->nazwa); else playerMsg("Nic");
	playerMsg("ochrona stóp:\t|_");
	if(eq[SLOT_BUTY]) playerMsg(eq[SLOT_BUTY]->nazwa); else playerMsg("Nic");
	playerMsg("ochrona g³owy:\t|_");
	if(eq[SLOT_HELM]) playerMsg(eq[SLOT_HELM]->nazwa); else playerMsg("Nic");
	playerMsg("w prawej rêce:\t|_");
	if(eq[SLOT_PREKA]) playerMsg(eq[SLOT_PREKA]->nazwa); else playerMsg("Nic");
	playerMsg("w lewej rêce: \t|_");
	if(eq[SLOT_LREKA]) playerMsg(eq[SLOT_LREKA]->nazwa); else playerMsg("Nic");
}
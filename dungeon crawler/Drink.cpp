#include "Drink.h"
#include "gra.h"
#include "item.h"

Drink::Drink(Gra *gra):
	Komenda(gra)
{
	nazwa="drink";
}


Drink::~Drink(void)
{
}

void Drink::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;
	Item* mikstura = gracz.przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);

	if (mikstura == NULL)
	{
		playerMsg("Nie masz przy sobie czegoœ takiego jak |0.", argumenty.argument1);
		return;
	}

	if (! mikstura->jestMikstura() )
	{
		playerMsg("|^|0 nie jest do picia!", mikstura->nazwa);
		return;
	}

	playerMsg("Wypijasz |0.", mikstura->nazwa);
	bool destroy = mikstura->drink(&gracz);
	gracz.przelicz();
	if (destroy)
	{
		gracz.przedmioty->usun(mikstura);
		delete mikstura;
	}
}

void Drink::manual()
{
	playerMsg("Synonimy:\n"
				"   drink(dri)\n\n"
				"U¿ycia:\n\n"
				"   drink <nazwa_mikstury> - wypija wskazan¹ miksturê. Mikstura musi siê znajdowaæ w inwentarzu, po wypicu zostanie ona zniszczona.\n\n"
				"SprawdŸ równie¿:\n"
				"   condition");
}
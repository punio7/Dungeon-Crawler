#include "Gra.h"
#include "Status.h"

void Gra::zdarzeniaCiagle()
{
	
	if ( !(gracz.statusy)->pusta() )
	{
		for (Status* aktualny : *gracz.statusy)
		{
			aktualny->aktywujExplor(&gracz, stoper.roznica());
		}

		gracz.usunNieatywneStatusy();		//usuwamy z listy statusy, kt�re si� sko�czy�y
	}
}
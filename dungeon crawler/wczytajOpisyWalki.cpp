#include "walka.h"

OpisyWalki::OpisyWalki()
{
	opisyGraczPudlo.push_back(L"Atakujesz, jednak przeciwnik wykonuje zwinny unik.");
	opisyGraczPudlo.push_back(L"Przeciwnik wykonuje zw�d, przez co chybiasz haniebnie.");
	opisyGraczPudlo.push_back(L"Wr�g uchyli� si� od ataku w ostatnim momencie.");
	opisyGraczPudlo.push_back(L"Zawaha�e� si� przez chwil�, przez co przeciwnik unikn�� ataku.");
	opisyGraczPudlo.push_back(L"Wykonujesz zamach, jednak chybiasz o jakie� p� mili.");
	opisyGraczPudlo.push_back(L"Sporo wysi�ku wk�adasz w ten atak, jednak�e chybiasz o w�os.");
	opisyGraczPudlo.push_back(L"Atakujesz niespodzianie, jednak przeciwnik unikn�� ciosu.");

	opisyGraczTrafienie.push_back(L"Atakujesz niespodziewanie, trafiaj�c zaskoczonego przeciwnika.");
	opisyGraczTrafienie.push_back(L"Wr�g na chwil� opuszcza gard�, co wykorzystujesz zadaj�c cios.");
	opisyGraczTrafienie.push_back(L"Wykonujesz efektowny piruet i trafiasz przeciwnika.");
	opisyGraczTrafienie.push_back(L"Cofasz si� o krok, po czym wykonujesz zamach trafiaj�c przeciwnika.");
	opisyGraczTrafienie.push_back(L"Tw�j precyzyjny cios przechodzi przez obron� przeciwnika.");

	opisyWrogPudlo.push_back(L"Przeciwnik ci� nie trafia.");

	opisyWrogTrafienie.push_back(L"Przeciwnik ci� trafia.");
}


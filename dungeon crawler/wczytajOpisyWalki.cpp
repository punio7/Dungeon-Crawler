#include "walka.h"

OpisyWalki::OpisyWalki()
{
	opisyGraczPudlo.push_back(L"Atakujesz, jednak przeciwnik wykonuje zwinny unik.");
	opisyGraczPudlo.push_back(L"Przeciwnik wykonuje zwód, przez co chybiasz haniebnie.");
	opisyGraczPudlo.push_back(L"Wróg uchyli³ siê od ataku w ostatnim momencie.");
	opisyGraczPudlo.push_back(L"Zawaha³eœ siê przez chwilê, przez co przeciwnik unikn¹³ ataku.");
	opisyGraczPudlo.push_back(L"Wykonujesz zamach, jednak chybiasz o jakieœ pó³ mili.");
	opisyGraczPudlo.push_back(L"Sporo wysi³ku wk³adasz w ten atak, jednak¿e chybiasz o w³os.");
	opisyGraczPudlo.push_back(L"Atakujesz niespodzianie, jednak przeciwnik unikn¹³ ciosu.");

	opisyGraczTrafienie.push_back(L"Atakujesz niespodziewanie, trafiaj¹c zaskoczonego przeciwnika.");
	opisyGraczTrafienie.push_back(L"Wróg na chwilê opuszcza gardê, co wykorzystujesz zadaj¹c cios.");
	opisyGraczTrafienie.push_back(L"Wykonujesz efektowny piruet i trafiasz przeciwnika.");
	opisyGraczTrafienie.push_back(L"Cofasz siê o krok, po czym wykonujesz zamach trafiaj¹c przeciwnika.");
	opisyGraczTrafienie.push_back(L"Twój precyzyjny cios przechodzi przez obronê przeciwnika.");

	opisyWrogPudlo.push_back(L"Przeciwnik ciê nie trafia.");

	opisyWrogTrafienie.push_back(L"Przeciwnik ciê trafia.");
}


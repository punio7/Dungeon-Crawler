#include "walka.h"

OpisyWalki::OpisyWalki()
{
	opisyGraczPudlo.push_back("Atakujesz, jednak przeciwnik wykonuje zwinny unik.");
	opisyGraczPudlo.push_back("Przeciwnik wykonuje zwód, przez co chybiasz haniebnie.");
	opisyGraczPudlo.push_back("Wróg uchyli³ siê od ataku w ostatnim momencie.");
	opisyGraczPudlo.push_back("Zawaha³eœ siê przez chwilê, przez co przeciwnik unikn¹³ ataku.");
	opisyGraczPudlo.push_back("Wykonujesz zamach, jednak chybiasz o jakieœ pó³ mili.");
	opisyGraczPudlo.push_back("Sporo wysi³ku wk³adasz w ten atak, jednak¿e chybiasz o w³os.");
	opisyGraczPudlo.push_back("Atakujesz niespodzianie, jednak przeciwnik unikn¹³ ciosu.");

	opisyGraczTrafienie.push_back("Atakujesz niespodziewanie, trafiaj¹c zaskoczonego przeciwnika.");
	opisyGraczTrafienie.push_back("Wróg na chwilê opuszcza gardê, co wykorzystujesz zadaj¹c cios.");
	opisyGraczTrafienie.push_back("Wykonujesz efektowny piruet i trafiasz przeciwnika.");
	opisyGraczTrafienie.push_back("Cofasz siê o krok, po czym wykonujesz zamach trafiaj¹c przeciwnika.");
	opisyGraczTrafienie.push_back("Twój precyzyjny cios przechodzi przez obronê przeciwnika.");

	opisyWrogPudlo.push_back("Przeciwnik ciê nie trafia.");

	opisyWrogTrafienie.push_back("Przeciwnik ciê trafia.");
}


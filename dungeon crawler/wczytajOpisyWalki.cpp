#include "walka.h"

OpisyWalki::OpisyWalki()
{
	opisyGraczPudlo.push_back("Atakujesz, jednak przeciwnik wykonuje zwinny unik.");
	opisyGraczPudlo.push_back("Przeciwnik wykonuje zw�d, przez co chybiasz haniebnie.");
	opisyGraczPudlo.push_back("Wr�g uchyli� si� od ataku w ostatnim momencie.");
	opisyGraczPudlo.push_back("Zawaha�e� si� przez chwil�, przez co przeciwnik unikn�� ataku.");
	opisyGraczPudlo.push_back("Wykonujesz zamach, jednak chybiasz o jakie� p� mili.");
	opisyGraczPudlo.push_back("Sporo wysi�ku wk�adasz w ten atak, jednak�e chybiasz o w�os.");
	opisyGraczPudlo.push_back("Atakujesz niespodzianie, jednak przeciwnik unikn�� ciosu.");

	opisyGraczTrafienie.push_back("Atakujesz niespodziewanie, trafiaj�c zaskoczonego przeciwnika.");
	opisyGraczTrafienie.push_back("Wr�g na chwil� opuszcza gard�, co wykorzystujesz zadaj�c cios.");
	opisyGraczTrafienie.push_back("Wykonujesz efektowny piruet i trafiasz przeciwnika.");
	opisyGraczTrafienie.push_back("Cofasz si� o krok, po czym wykonujesz zamach trafiaj�c przeciwnika.");
	opisyGraczTrafienie.push_back("Tw�j precyzyjny cios przechodzi przez obron� przeciwnika.");

	opisyWrogPudlo.push_back("Przeciwnik ci� nie trafia.");

	opisyWrogTrafienie.push_back("Przeciwnik ci� trafia.");
}


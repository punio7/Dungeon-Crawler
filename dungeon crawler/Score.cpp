#include "Score.h"
#include "gra.h"


Score::Score(Gra *gra):
	Komenda(gra)
{
	nazwa="score";
}


Score::~Score(void)
{
}

void Score::execute(ParseDTO argumenty)
{
	//gra->gracz.wypisz_staty();
	wypiszStaty(&(gra->gracz));
}

void Score::manual()
{
	Komenda::manual();	//TODO wpisac manual dla danej komendy
}

void Score::wypiszStaty(Postac *postac)
{
	playerMsg("Wojownik |0 |1 |2 |3 poziomu |4.",
		postac->imie, postac->rasa->nazwa, postac->klasa->nazwa, intToStr(postac->poziom));
	
	playerMsg("Cecha\t\tBazowa\tRasowy\tKlasowy\tBonusy\t£¹czna");
	//cout<<"Sila\t\t"<<sil_baz<<"\t"<<rasa->si<<"%\t"<<klasa->getSi(poziom)<<"%\t"<<sil_bon<<"\t"<<sil_calk<<endl;
	playerMsg("Si³a\t\t|0\t|1%\t|2%\t|3\t|4",
		intToStr(postac->sil_baz), intToStr(postac->rasa->si*100), intToStr(postac->klasa->getSi(postac->poziom)*100), 
		intToStr(postac->sil_bon), intToStr(postac->sil_calk));
	//cout<<"Zrecznosc\t"<<zr_baz<<"\t"<<rasa->zr<<"%\t"<<klasa->getZr(poziom)<<"%\t"<<zr_bon<<"\t"<<zr_calk<<endl;
	playerMsg("Zrêcznoœæ\t|0\t|1%\t|2%\t|3\t|4",
		intToStr(postac->zr_baz), intToStr(postac->rasa->zr*100), intToStr(postac->klasa->getZr(postac->poziom)*100), 
		intToStr(postac->zr_bon), intToStr(postac->zr_calk));
	//cout<<"Zwinnosc\t"<<zw_baz<<"\t"<<rasa->zw<<"%\t"<<klasa->getZw(poziom)<<"%\t"<<zw_bon<<"\t"<<zw_calk<<endl;
	playerMsg("Zwinnoœæ\t|0\t|1%\t|2%\t|3\t|4",
		intToStr(postac->zw_baz), intToStr(postac->rasa->zw*100), intToStr(postac->klasa->getZw(postac->poziom)*100), 
		intToStr(postac->zw_bon), intToStr(postac->zw_calk));
	//cout<<"Wytrzymalosc\t"<<wyt_baz<<"\t"<<rasa->wyt<<"%\t"<<klasa->getWyt(poziom)<<"%\t"<<wyt_bon<<"\t"<<wyt_calk<<endl;
	playerMsg("Wytrzyma³oœæ\t|0\t|1%\t|2%\t|3\t|4",
		intToStr(postac->wyt_baz), intToStr(postac->rasa->wyt*100), intToStr(postac->klasa->getWyt(postac->poziom)*100), 
		intToStr(postac->wyt_bon), intToStr(postac->wyt_calk));
	//cout<<"Zywotnosc\t"<<zyw_baz<<"\t"<<rasa->zyw<<"%\t"<<klasa->getZyw(poziom)<<"%\t"<<zyw_bon<<"\t"<<zyw_calk<<endl<<endl;
	playerMsg("¯ywotnoœæ\t|0\t|1%\t|2%\t|3\t|4",
		intToStr(postac->zyw_baz), intToStr(postac->rasa->zyw*100), intToStr(postac->klasa->getZyw(postac->poziom)*100), 
		intToStr(postac->zyw_bon), intToStr(postac->zyw_calk));
	
	playerMsg("\nAtrybut\t\tCecha\tPoziom\tSprzet\tBonusy\tModyf.\tRazem");
	//cout<<"Atak\t\t"<<at_cecha<<"\t"<<at_poz<<"\t"<<at_eq<<"\t"<<at_bon<<"\t+"<<at_mod<<"%\t"<<at_calk<<endl;
	playerMsg("Atak\t\t|0\t|1\t|2\t|3\t|4%\t|5",
		intToStr(postac->at_cecha), intToStr(postac->at_poz), intToStr(postac->at_eq), intToStr(postac->at_bon), 
		intToStr(postac->at_mod), intToStr(postac->at_calk));
	//cout<<"Obrona\t\t"<<obr_cecha<<"\t"<<obr_poz<<"\t"<<obr_eq<<"\t"<<obr_bon<<"\t+"<<obr_mod<<"%\t"<<obr_calk<<endl;
	playerMsg("Obrona\t\t|0\t|1\t|2\t|3\t|4%\t|5",
		intToStr(postac->obr_cecha), intToStr(postac->obr_poz), intToStr(postac->obr_eq), intToStr(postac->obr_bon), 
		intToStr(postac->obr_mod), intToStr(postac->obr_calk));
	//cout<<"Zdrowie\t\t"<<zdr_cecha<<"\t"<<zdr_poz<<"\t"<<zdr_eq<<"\t"<<zdr_bon<<"\t+"<<zdr_mod<<"%\t"<<zdr_calk<<endl;
	playerMsg("Zdrowie\t\t|0\t|1\t|2\t|3\t|4%\t|5",
		intToStr(postac->zdr_cecha), intToStr(postac->zdr_poz), intToStr(postac->zdr_eq), intToStr(postac->zdr_bon),
		intToStr(postac->zdr_mod), intToStr(postac->zdr_calk));
	//cout<<"Pancerz\t\t"<<panc_cecha<<"\t\t"<<panc_eq<<"\t"<<panc_bon<<"\t+"<<panc_mod<<"%\t"<<panc_calk<<"\t"<<ochr_calk/6<<'%'<<endl;
	playerMsg("Pancerz\t\t|0\t\t|1\t|2\t|3%\t|4\t|5%",
		intToStr(postac->panc_cecha), intToStr(postac->panc_eq), intToStr(postac->panc_bon), intToStr(postac->panc_mod),
		intToStr(postac->panc_calk), intToStr(postac->ochr_calk/6));
	//cout<<"Zmeczenie\t"<<zm_cecha<<"\t"<<zm_poz<<"\t"<<zm_eq<<"\t"<<zm_bon<<"\t+"<<zm_mod<<"%\t"<<zm_calk<<endl;
	playerMsg("Zmêczenie\t|0\t|1\t|2\t|3\t|4%\t|5",
		intToStr(postac->zm_cecha), intToStr(postac->zm_poz), intToStr(postac->zm_eq), intToStr(postac->zm_bon),
		intToStr(postac->zm_mod), intToStr(postac->zm_calk));
	//cout<<"Obrazenia\t"<<dmg<<"\t\t"<<dmg_eq<<"\t"<<dmg_bon<<"\t+"<<dmg_mod<<"%\t"<<dmg_calk<<endl<<endl;
	playerMsg("Obra¿enia\t|0\t\t|1\t|2\t|3%\t|4",
		intToStr(postac->dmg), intToStr(postac->dmg_eq), intToStr(postac->dmg_bon), 
		intToStr(postac->dmg_mod), intToStr(postac->dmg_calk));
}
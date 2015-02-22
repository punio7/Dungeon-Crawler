#include "parser.h"

using namespace std;

Parser::Parser()
{
	komendy = new Command_tree;
	create_command_tree();
}

void Parser::pobierz_linie()
{
	getline(cin, linia);
}

void Parser::parsuj()
{
	if (!linia.empty()) 
	{
		while (!linia.empty()) 
		{
			char ch = linia[0];
			if (ch==' ' || ch=='\t' || ch=='\v' || ch=='\f' || ch=='\r') linia.erase(linia.begin());	//dopoki na poaczatku sa spacje to je kasuj
			else break;
		}

		int koniec_komendy=linia.find(' ',0);	//szukam najblizszej spacji i oznaczam jej pozycje (oznacza ona koniec komendy)
		if (koniec_komendy==string::npos) koniec_komendy=linia.length();
		string Skomenda=linia.substr(0,koniec_komendy);	//wyodrebniam tekst do spacji
		komenda=znajdz(Skomenda);						//zamieniamy tekst na komende

		linia=linia.substr(koniec_komendy,linia.length()-koniec_komendy);	//wyrzucamy tekst komendy z linii
		wyciagnij_argument(1);
		wyciagnij_argument(2);

		argumenty.clear();
		argumenty.argument1 = argument1;
		argumenty.argument2 = argument2;
		argumenty.ktory1 = ktory1;
		argumenty.ktory2 = ktory2;
		argumenty.kierunek1 = kierunek1;
		argumenty.komenda1 = komenda1;
	}
	else komenda=COMM_NOCOMM;	//jezeli linia jest pusta
}

void Parser::wyciagnij_argument(int miejsce)
{
		while (!linia.empty()) 
		{
			char ch = linia[0];
			if (ch==' ' || ch=='\t' || ch=='\v' || ch=='\f' || ch=='\r') linia.erase(linia.begin());	//czyscimy poczatek linii ze spacjii
			else break;
		}
		if(!linia.empty())
		{
			char ch = linia[0];
			if ( ch>='0' && ch<='9')	//jezeli argument zaczyna sie od cyfry
			{
				int koniec_liczby=linia.find('.',0);	//szukamy kropki, oznaczajacej koniec liczby
				if (koniec_liczby!=string::npos)		//jezeli znaleziono kropke
				{
					string liczba=linia.substr(0,koniec_liczby);	//liczbe roboczo zapisujemy jako oddzielny string
					switch (miejsce)		//wrzucamy znaleziona liczbe do odpowiedniego wyjscia parsera
					{
					case 1: 
						ktory1=atoi(liczba.c_str());
						break;
					case 2:
						ktory2=atoi(liczba.c_str());
						break;
					default:
						cout<<"Blad parsera, niepoprawne wywolanie funkcji wyciagnij_argument, przekaz to malpie ktora to pisala."<<endl;
					}			
					linia=linia.substr(koniec_liczby+1,linia.length()-koniec_liczby);	//wyrzucamy liczbe i kropke z linii aby nie balaganila
				}//jezeli nie znaleziono kropki to nic sie nie dzieje- liczba pozostaje w argumencie
			}
			else	//jezeli gracz nie podal zadnej liczby, domyslamy sie iz chodzi o pierwszy z brzegu
			{
				switch (miejsce)
				{
				case 1:
					ktory1=1;
					break;
				case 2:
					ktory2=1;
					break;
				default:
					cout<<"Blad parsera, niepoprawne wywolanie funkcji wyciagnij_argument, przekaz to malpie ktora to pisala."<<endl;
				}
			}
			if ((!linia.empty())&&(linia[0]=='\"'))		//jezeli linia zaczyna sie od cudzyslowa
			{
				int koniec_cytatu=linia.find('\"',1);	//szukamy drugiego cudzyslowa
				if (koniec_cytatu!=string::npos)		//jezeli znaleziono drugi cudzyslow
				{
					switch (miejsce)		//ladujemy tekst miedzy cudzyslowami do odpowiedniego argumentu
					{
					case 1:
						argument1=linia.substr(1,koniec_cytatu-1);
						kierunek1=znajdzKierunek(argument1);
						komenda1=znajdz(argument1);
						break;
					case 2:
						argument2=linia.substr(1,koniec_cytatu-1);
						break;
					default:
						cout<<"Blad parsera, niepoprawne wywolanie funkcji wyciagnij_argument, przekaz to malpie ktora to pisala."<<endl;
					}
					linia=linia.substr(koniec_cytatu+1,linia.length()-koniec_cytatu);	//i wyrzucamy go z linii
				}//jezeli nie znaleziona drugiego cudzyslowu to nic sie nie dzieje- cudzyslow pozostaje w argumencie
			}
			else
			{
				int koniec_argumentu=linia.find(' ',0);
				if (koniec_argumentu!=string::npos)
				{
					switch (miejsce)
					{
					case 1:
						argument1=linia.substr(0,koniec_argumentu);
						kierunek1=znajdzKierunek(argument1);
						komenda1=znajdz(argument1);
						break;
					case 2:
						argument2=linia.substr(0,koniec_argumentu);
						break;
					default:
						cout<<"Blad parsera, niepoprawne wywolanie funkcji wyciagnij_argument, przekaz to malpie ktora to pisala."<<endl;
					}
					linia=linia.substr(koniec_argumentu+1,linia.length()-koniec_argumentu);
				}
				else
				{
					switch (miejsce)
					{
					case 1:
						argument1=linia;
						kierunek1=znajdzKierunek(argument1);
						komenda1=znajdz(argument1);
						linia.erase();
						break;
					case 2:
						argument2=linia;
						linia.erase();
						break;
					default:
						cout<<"Blad parsera, niepoprawne wywolanie funkcji wyciagnij_argument, przekaz to malpie ktora to pisala."<<endl;
					}
				}
			}
		}
		else	//zapomnia³eœ chyba o czymœ kurwa? a moze wyzerowac argument je¿eli gracz go nie podal?
		{		//if (linia.empty())
			switch (miejsce)
			{
			case 1:
				argument1.erase();
				break;
			case 2:
				argument2.erase();
				break;
			default:
				cout<<"Blad parsera, niepoprawne wywolanie funkcji wyciagnij_argument, przekaz to malpie ktora to pisala."<<endl;
			}
		}
}

Ekomenda Parser::znajdz(string& command)
{
	Command_tree* aktualny=komendy;
	char c;
	for (int i=0;i<command.length();i++)
	{
		c=command[i];
		if (c=='ê' || c=='ó' || c=='¹' || c=='œ' || c=='³' || c=='¿' || c=='Ÿ' || c=='æ' || c=='ñ') return COMM_WRONG;
		c=tolower(c);
		c-='a';
		if ((c < 0)||(c > ILOSC_ZNAKOW_W_ALFABECIE-1)) return COMM_WRONG;
		aktualny=(aktualny->son)[c];
		if (aktualny==NULL) return COMM_WRONG;
	}
	return aktualny->command;
}

KierunekSwiata Parser::znajdzKierunek(string& kierunek)
{
	string porownawczy = "";
	if (kierunek[0] == 'n')
	{
		porownawczy = "north";
		if (porownawczy.find(kierunek) != -1) return NORTH;
		else return KIERUNEK_NIEPOPRAWNY;
	}
	if (kierunek[0] == 's')
	{
		porownawczy = "south";
		if (porownawczy.find(kierunek) != -1) return SOUTH;
		else return KIERUNEK_NIEPOPRAWNY;
	}
	if (kierunek[0] == 'w')
	{
		porownawczy = "west";
		if (porownawczy.find(kierunek) != -1) return WEST;
		else return KIERUNEK_NIEPOPRAWNY;
	}
	if (kierunek[0] == 'e')
	{
		porownawczy = "east";
		if (porownawczy.find(kierunek) != -1) return EAST;
		else return KIERUNEK_NIEPOPRAWNY;
	}
	if (kierunek[0] == 'u')
	{
		porownawczy = "up";
		if (porownawczy.find(kierunek) != -1) return UP;
		else return KIERUNEK_NIEPOPRAWNY;
	}
	if (kierunek[0] == 'd')
	{
		porownawczy = "down";
		if (porownawczy.find(kierunek) != -1) return DOWN;
		else return KIERUNEK_NIEPOPRAWNY;
	}
	
	return KIERUNEK_NIEPOPRAWNY;
}

void Parser::oproznij_we()
{
	if (!cin.eof()) cin.ignore(999,'\n');
}
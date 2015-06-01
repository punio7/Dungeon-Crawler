#include "parser.h"

;using namespace std;

void Parser::create_command_tree()
{
	//komendy ni¿ej w liœcie maj¹ wiêkszy priorytet

	///////////// A //////////////

	///////////// B //////////////
	create_command(L"buy", COMM_BUY);

	///////////// C //////////////
	create_command(L"cheat", COMM_CHEAT);
	create_command(L"commands", COMM_MANUAL);
	create_command(L"consider", COMM_CONSIDER);
	create_command(L"condition", COMM_CONDITION);

	///////////// D //////////////
	create_command(L"drink", COMM_DRINK);
	create_command(L"drop", COMM_DROP);
	create_command(L"down", COMM_DOWN);

	///////////// E //////////////
	create_command(L"equipment", COMM_EQUIPMENT);
	create_command(L"examine",COMM_EXAMINE);
	create_command(L"eat", COMM_EAT);
	create_command(L"east", COMM_EAST);

	///////////// F //////////////

	///////////// G //////////////
	create_command(L"get", COMM_TAKE);
	create_command(L"go", COMM_GO);

	///////////// H //////////////
	create_command(L"help", COMM_MANUAL);
	create_command(L"hold", COMM_HOLD);

	///////////// I //////////////
	create_command(L"inventory", COMM_INVENTORY);

	///////////// J //////////////
	create_command(L"journal", COMM_JOURNAL);

	///////////// K //////////////
	create_command(L"kill", COMM_KILL);
	
	///////////// L //////////////
	create_command(L"list", COMM_LIST);
	create_command(L"look", COMM_LOOK);

	///////////// M //////////////
	create_command(L"manual", COMM_MANUAL);
	create_command(L"map", COMM_MAP);

	///////////// N //////////////
	create_command(L"north", COMM_NORTH);

	///////////// O //////////////
	create_command(L"offer", COMM_OFFER);
	create_command(L"open", COMM_OPEN);

	///////////// P //////////////
	create_command(L"pull", COMM_PULL);
	create_command(L"push", COMM_PUSH);
	create_command(L"put", COMM_PUT);

	///////////// Q //////////////
	create_command(L"quit", COMM_QUIT);

	///////////// R //////////////
	create_command(L"remove", COMM_REMOVE);

	///////////// S //////////////
	create_command(L"score", COMM_SCORE);
	create_command(L"sell", COMM_SELL);
	create_command(L"scan", COMM_SCAN);
	create_command(L"south", COMM_SOUTH);

	///////////// T //////////////
	create_command(L"test", COMM_TEST);
	create_command(L"talk", COMM_TALK);
	create_command(L"turn", COMM_TURN);
	create_command(L"train", COMM_TRAIN);
	create_command(L"take", COMM_TAKE);

	///////////// U //////////////
	create_command(L"unlock", COMM_UNLOCK);
	create_command(L"up", COMM_UP);

	///////////// W //////////////
	create_command(L"wield",COMM_WIELD);
	create_command(L"wear", COMM_WEAR);
	create_command(L"west", COMM_WEST);

	///////////// V //////////////

	///////////// X //////////////

	///////////// Y //////////////

	///////////// Z //////////////
	
}

void Parser::create_command(wchar_t* Ccommand, Ekomenda Kcommand)
{
	char c;							//iterator obecnego znaku
	Command_tree* aktualny=komendy;	//wskaznik pomocniczy
	for (int i=0;Ccommand[i]!=0;i++)	//dopoki nie dojdziemy do konca c-wstringu
	{
		c=(Ccommand[i]-'a');			//od kodu znaku odejmuje kod znaku 'a'- otrzymuje iterator
		if ((aktualny->son)[c]==NULL)	//jezeli dany son nie zostal powolany
			(aktualny->son)[c]= new Command_tree;		//to go powoluje
		aktualny=(aktualny->son)[c];	//przelaczam sie na niego
		aktualny->command=Kcommand;		//ustawiam komende
	}
}
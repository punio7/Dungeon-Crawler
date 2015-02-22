#include "parser.h"

;using namespace std;

void Parser::create_command_tree()
{
	//komendy ni¿ej w liœcie maj¹ wiêkszy priorytet

	///////////// A //////////////

	///////////// B //////////////
	create_command("buy", COMM_BUY);

	///////////// C //////////////
	create_command("cheat", COMM_CHEAT);
	create_command("commands", COMM_MANUAL);
	create_command("consider", COMM_CONSIDER);
	create_command("condition", COMM_CONDITION);

	///////////// D //////////////
	create_command("drink", COMM_DRINK);
	create_command("drop", COMM_DROP);
	create_command("down", COMM_DOWN);

	///////////// E //////////////
	create_command("equipment", COMM_EQUIPMENT);
	create_command("examine",COMM_EXAMINE);
	create_command("east", COMM_EAST);

	///////////// F //////////////

	///////////// G //////////////
	create_command("get", COMM_TAKE);
	create_command("go", COMM_GO);

	///////////// H //////////////
	create_command("help", COMM_MANUAL);
	create_command("hold", COMM_HOLD);

	///////////// I //////////////
	create_command("inventory", COMM_INVENTORY);

	///////////// J //////////////
	create_command("journal", COMM_JOURNAL);

	///////////// K //////////////
	create_command("kill", COMM_KILL);
	
	///////////// L //////////////
	create_command("list", COMM_LIST);
	create_command("look", COMM_LOOK);

	///////////// M //////////////
	create_command("manual", COMM_MANUAL);
	create_command("map", COMM_MAP);

	///////////// N //////////////
	create_command("north", COMM_NORTH);

	///////////// O //////////////
	create_command("offer", COMM_OFFER);
	create_command("open", COMM_OPEN);

	///////////// P //////////////
	create_command("pull", COMM_PULL);
	create_command("push", COMM_PUSH);
	create_command("put", COMM_PUT);

	///////////// Q //////////////
	create_command("quit", COMM_QUIT);

	///////////// R //////////////
	create_command("remove", COMM_REMOVE);

	///////////// S //////////////
	create_command("score", COMM_SCORE);
	create_command("sell", COMM_SELL);
	create_command("scan", COMM_SCAN);
	create_command("south", COMM_SOUTH);

	///////////// T //////////////
	create_command("test", COMM_TEST);
	create_command("talk", COMM_TALK);
	create_command("turn", COMM_TURN);
	create_command("train", COMM_TRAIN);
	create_command("take", COMM_TAKE);

	///////////// U //////////////
	create_command("unlock", COMM_UNLOCK);
	create_command("up", COMM_UP);

	///////////// W //////////////
	create_command("wield",COMM_WIELD);
	create_command("wear", COMM_WEAR);
	create_command("west", COMM_WEST);

	///////////// V //////////////

	///////////// X //////////////

	///////////// Y //////////////

	///////////// Z //////////////
	
}

void Parser::create_command(char* Ccommand, Ekomenda Kcommand)
{
	char c;							//iterator obecnego znaku
	Command_tree* aktualny=komendy;	//wskaznik pomocniczy
	for (int i=0;Ccommand[i]!=0;i++)	//dopoki nie dojdziemy do konca c-stringu
	{
		c=(Ccommand[i]-'a');			//od kodu znaku odejmuje kod znaku 'a'- otrzymuje iterator
		if ((aktualny->son)[c]==NULL)	//jezeli dany son nie zostal powolany
			(aktualny->son)[c]= new Command_tree;		//to go powoluje
		aktualny=(aktualny->son)[c];	//przelaczam sie na niego
		aktualny->command=Kcommand;		//ustawiam komende
	}
}
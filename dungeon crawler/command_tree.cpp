#include "command_tree.h"

;using namespace std;

Command_tree::Command_tree()
{
	command = COMM_WRONG;
	for (int i=0;i<ILOSC_ZNAKOW_W_ALFABECIE;i++) son[i]=NULL;

}
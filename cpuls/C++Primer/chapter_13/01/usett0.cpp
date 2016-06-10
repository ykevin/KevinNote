
#include <iostream>
#include "tabtenn0.h"

int main(void)
{
	using std::cout;

	TableTennisPlayer player1("Kevin", "Yang", true);
	TableTennisPlayer player2("Eille", "Yuan", false);
	player1.Name();
	if(player1.HasTable())
		cout << ": has a table.\n";
   	else
		cout << ": hasn't a table.\n";

	player2.Name();
	if(player2.HasTable())	
		cout << ": has a table.\n";
   	else
		cout << ": hasn't a table.\n";
	return 0;
}

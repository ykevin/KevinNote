
#include <iostream>
#include "tabtenn0.h"

int main(void)
{
	using std::cout;

	TableTennisPlayer player1("Kevin", "Yang", true);
	RatedPlayer rplayer1(1140, "Eille", "Yuan", false);
	player1.Name();
	if(player1.HasTable())
		cout << ": has a table.\n";
   	else
		cout << ": hasn't a table.\n";

	rplayer1.Name();
	if(rplayer1.HasTable())	
		cout << ": has a table.\n";
   	else
		cout << ": hasn't a table.\n";

	cout << "Name : ";
	rplayer1.Name();
	cout << ": Rating: " << rplayer1.Rating() << std::endl;
	return 0;
}

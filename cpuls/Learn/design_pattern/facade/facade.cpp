
#include <iostream>
#include "letterprocess.h"
#include "letterprocessimpl.h"
#include "modernpostoffice.h"

using namespace std;

void DoItByPostOffice()
{
	ModernPostOffice modernPostOffice;
	string context = "Hello ,my name is kevin ,I'd like ....";
	string address = "Happy Road No.666, FoShan City, China";
	modernPostOffice.SendLetter(context, address);
}

int main(void)
{
	DoItByPostOffice();
	return 0;
}

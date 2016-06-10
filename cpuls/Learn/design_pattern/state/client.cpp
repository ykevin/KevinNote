
#include <iostream>
#include "context.h"
#include "concretestateA.h"
#include "concretestateB.h"

using namespace std;

int main(int argc, char *argv[])
{

	Context * c = new Context();
	c->request();
	c->request();
	//c->request();

	delete c;
	return 0;
}

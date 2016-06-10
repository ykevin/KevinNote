
#include <iostream>
#include "context.hpp"
#include "backdoor.hpp"
#include "givengreenlight.hpp"
#include "blockenemy.hpp"

using namespace std;

int main(void)
{
	CContext *pContext;
	pContext = new CContext(new CBackDoor());
	pContext->Operate();
	delete pContext;

	
	pContext = new CContext(new CGivenGreenLight());
	pContext->Operate();
	delete pContext;

	pContext = new CContext(new CBlockEnemy());
	pContext->Operate();
	delete pContext;

	return 0;
}


#include "concretestateA.h"
#include "concretestateB.h"
#include "context.h"
#include <iostream>

using namespace std;

State *ConcreteStateA::m_pState = NULL;
ConcreteStateA::ConcreteStateA() {}

ConcreteStateA::~ConcreteStateA() {}

State *ConcreteStateA::Instance()
{
	if(NULL == m_pState)
	{
		m_pState = new ConcreteStateA();
	}

	return m_pState;
}

void ConcreteStateA::handle(Context *c)
{
	cout << "doing something in State A\n, change state to B " << endl;
	c->changeState(ConcreteStateB::Instance());
}

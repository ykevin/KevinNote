

#include "obeserver.hpp"
#include <string>
#include <iostream>

using namespace std;

class ConcreteObeserver : public Obeserver
{
	public:
		ConcreteObeserver(string name);
		virtual ~ConcreteObeserver();
		virtual void update(Subject *sub);

	private:
		string m_objName;
		int m_obeserverState;

};

ConcreteObeserver::ConcreteObeserver(string name) 
{
	m_objName = name;
}

ConcreteObeserver::~ConcreteObeserver() 
{
	
}

void ConcreteObeserver::update(Subject *sub)
{
	m_obeserverState = sub->getState();
	cout << "update obeserver [" << m_objName << "] state: " << m_obeserverState << endl;
}

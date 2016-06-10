
#include <iostream>
#include "subject.hpp"
#include "obeserver.hpp"
#include "concreteobeserver.hpp"
#include "concretesubject.hpp"

using namespace std;

int main()
{
	Subject *subject = new ConcreteSubject();
	Obeserver *objA = new ConcreteObeserver("A");
	Obeserver *objB = new ConcreteObeserver("B");

	subject->attach(objA);
	subject->attach(objB);

	subject->setState(1);
	subject->notify();

	cout << "-----------------" << endl;
	subject->detach(objB);
	subject->setState(2);

	subject->notify();

	delete subject;
	delete objA;
	delete objB;

	return 0;
}

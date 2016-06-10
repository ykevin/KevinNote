
#include "decorator.hpp"

int main()
{
	Component *pComponent = new ConcreteComponent();
	ConcreteDecorator *pConDecorator = new ConcreteDecorator();

	pConDecorator->setComponent(pComponent);
	pConDecorator->operation();
//	pConDecorator->addBehavior();

	delete pComponent;
	delete pConDecorator;

	return 0;
}

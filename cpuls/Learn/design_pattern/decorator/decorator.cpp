
#include <iostream>
#include "decorator.hpp"


Decorator::Decorator()
{}

Decorator::~Decorator()
{}

void Decorator::operation()
{
	mComponent->operation();
}

void Decorator::setComponent(Component *pComponent)
{
	this->mComponent = pComponent;
}

ConcreteDecorator::ConcreteDecorator()
{}

ConcreteDecorator::~ConcreteDecorator()
{}

void ConcreteDecorator::addBehavior()
{
	std::cout << "ConcreteDecorator's addBehavior" << std::endl;
}




#include <iostream>
#include "component.hpp"

Component::Component()
{}

Component::~Component() 
{}

ConcreteComponent::ConcreteComponent()
{

}

ConcreteComponent::~ConcreteComponent()
{}

void ConcreteComponent::operation()
{
	std::cout << "ConcreteComponent's operation !" << std::endl;
}

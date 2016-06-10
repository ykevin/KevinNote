#include "SimpleFactory.hpp"
#include <iostream>


AbstractFactory::AbstractFactory(){

}


AbstractFactory::~AbstractFactory(){

}


SimpleFactory::SimpleFactory(){

}


SimpleFactory::~SimpleFactory(){

}


AbstractProduct* SimpleFactory::CreateProduct(int type){
	AbstractProduct* temp = NULL;
	switch(type)
	{
		case 1:
			temp = new ProductA();
			break;
		case 2:
			temp = new ProductB();
			break;
		default:
			break;

	}
	return temp;

}


#include "SimpleFactory.hpp"
#include <iostream>


int main(){
	AbstractFactory* factory = new SimpleFactory();
	AbstractProduct* product = factory->CreateProduct(1);
	product->operation();
	delete product;
	product = NULL;

	product = factory->CreateProduct(2);
	product->operation();
	delete product;
	product = NULL;
	return 0;
}



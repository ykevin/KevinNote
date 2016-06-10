#pragma once

#include "AbsrtactProduct.hpp"

class AbstractFactory {
	public :
		AbstractFactory();
		virtual ~AbstractFactory();
		virtual AbstractProduct* CreateProduct(int type) = 0;
};

class SimpleFactory:public AbstractFactory{

	public:
		SimpleFactory();
		~SimpleFactory();

	public:
		AbstractProduct* CreateProduct(int type);

};

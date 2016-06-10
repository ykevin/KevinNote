
#include "AbsrtactProduct.hpp"
#include <iostream>

using namespace std;

AbstractProduct::AbstractProduct()
{

}

AbstractProduct::~AbstractProduct()
{

}

ProductA::ProductA()
{

}

ProductA::~ProductA()
{

}

void ProductA::operation()
{
	cout << "ProductA operation!" << endl;
}


ProductB::ProductB()
{

}

ProductB::~ProductB()
{

}

void ProductB::operation()
{
	cout << "ProductB operation!" << endl;
}

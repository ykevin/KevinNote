#pragma once
#include "iproduct.h"
#include <iostream>

using namespace std;

class CHouse :
	public IProduct
{
	public:
		CHouse(void);
		~CHouse(void);
		void BeProducted();
		void BeSelled();

};

CHouse::CHouse(void)
{

}
CHouse::~CHouse(void)
{

}
void CHouse::BeProducted()
{
	cout << "生产出的房子是这个样子的..." << endl;

}
void CHouse::BeSelled()
{
	cout << "生产出的房子卖出去了..." << endl;

}



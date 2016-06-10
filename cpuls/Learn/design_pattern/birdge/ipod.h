#pragma once
#include "iproduct.h"
#include <iostream>

class CIPod :
	public IProduct
{
	public:
		CIPod(void);
		~CIPod(void);
		void BeProducted();
		void BeSelled();

};

CIPod::CIPod(void)
{

}
CIPod::~CIPod(void)
{

}
void CIPod::BeProducted()
{
	cout << "生产出的ipod是这个样子的..." << endl;

}
void CIPod::BeSelled()
{
	cout << "生产出的ipod卖出去了..." << endl;

}

#pragma once

#include "iproduct.h"
#include <iostream>

using namespace std;

class CClothes :
	public IProduct
{
	public:
		CClothes(void);
		~CClothes(void);
		void BeProducted();
		void BeSelled();
};

CClothes::CClothes(void)
{

}
CClothes::~CClothes(void)
{

}
void CClothes::BeProducted()
{
	cout << "生产出的衣服是这个样子的..." << endl;

}
void CClothes::BeSelled()
{
	cout << "生产出的衣服卖出去了..." << endl;

}

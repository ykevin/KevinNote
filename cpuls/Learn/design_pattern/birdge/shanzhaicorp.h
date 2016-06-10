
#pragma once

#include "newcorp.h"
#include "house.h"
#include <iostream>

using namespace std;

class CShanZhaiCorp: public CNewCorp {
	public:
		CShanZhaiCorp(IProduct *pproduct);
		~CShanZhaiCorp();
		void MakeMoney();
};

CShanZhaiCorp::CShanZhaiCorp(IProduct *pproduct) :CNewCorp(pproduct)
{

}

CShanZhaiCorp::~CShanZhaiCorp(void)
{
	
}

void CShanZhaiCorp::MakeMoney()
{
	this->CNewCorp::MakeMoney();
	cout << "shanzhai get  money" << endl;
}

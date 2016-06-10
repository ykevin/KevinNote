
#pragma once

#include "newcorp.h"
#include "house.h"
#include <iostream>

using namespace std;

class CNewHouseCorp: public CNewCorp {
	public:
		CNewHouseCorp(CHouse *pHouse);
		~CNewHouseCorp();
		void MakeMoney();
};

CNewHouseCorp::CNewHouseCorp(CHouse *pHouse) :CNewCorp(pHouse)
{

}

CNewHouseCorp::~CNewHouseCorp(void)
{
	
}

void CNewHouseCorp::MakeMoney()
{
	this->CNewCorp::MakeMoney();
	cout << "house get big money" << endl;
}

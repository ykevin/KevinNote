
#pragma once
#include "iproduct.h"

class CNewCorp{
	public:
		CNewCorp(IProduct *pproduct);
		virtual ~CNewCorp(void);
		void MakeMoney();
	private:
		IProduct *m_pProduct;
};

CNewCorp::CNewCorp(IProduct *pproduct)
{
	this->m_pProduct= pproduct;
}

CNewCorp::~CNewCorp(void) {}

void CNewCorp::MakeMoney()
{
	this->m_pProduct->BeProducted();
	this->m_pProduct->BeSelled();
}


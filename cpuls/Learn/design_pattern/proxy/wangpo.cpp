#include "wangpo.hpp"


CWangPo::CWangPo(IKindWomen *pKindWomen)
{
	this->m_pKindWomen = pKindWomen;
}

CWangPo::~CWangPo()
{
	delete this->m_pKindWomen;
}

void CWangPo::HappyWithMan()
{
	this->m_pKindWomen->HappyWithMan();
}

void CWangPo::MakeEyesWithMan()
{
	this->m_pKindWomen->MakeEyesWithMan();
}

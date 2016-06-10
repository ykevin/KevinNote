
#include "context.hpp"

CContext::CContext(IStrategy *pStrategy)
{
	this->m_pStrategy = pStrategy;
}

CContext::~CContext() 
{
	delete this->m_pStrategy;
}

void CContext::Operate()
{
	this->m_pStrategy->Operate();
}

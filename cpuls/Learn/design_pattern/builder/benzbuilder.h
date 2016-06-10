
#pragma once 
#include "icarbuilder.h"
#include "carmodel.h"
#include <iostream>
#include <vector>

using namespace std;

class CBenzBuilder : public ICarBuilder {
	public:
		CBenzBuilder();
		~CBenzBuilder();
		void SetSequence(vector<string> *pSeq);
		CCarModel *GetCarModel();
	private:
		CCarModel *m_pBenz;
};

CBenzBuilder::CBenzBuilder()
{
	m_pBenz = new CBenzModel();
}

CBenzBuilder::~CBenzBuilder()
{
	delete m_pBenz;
}

void CBenzBuilder::SetSequence(vector<string> *pSeq)
{
	m_pBenz->SetSequence(pSeq);
}

CCarModel * CBenzBuilder::GetCarModel()
{
	    return m_pBenz;
}


#pragma once 
#include "icarbuilder.h"
#include "carmodel.h"
#include <iostream>
#include <vector>

using namespace std;

class CBMWBuilder : public ICarBuilder {
	public:
		CBMWBuilder();
		~CBMWBuilder();
		void SetSequence(vector<string> *pSeq);
		CCarModel *GetCarModel();
	private:
		CCarModel *m_pBMW;
};

CBMWBuilder::CBMWBuilder()
{
	m_pBMW = new CBMWModel();
}

CBMWBuilder::~CBMWBuilder()
{
	delete m_pBMW;
}

void CBMWBuilder::SetSequence(vector<string> *pSeq)
{
	m_pBMW->SetSequence(pSeq);
}

CCarModel * CBMWBuilder::GetCarModel()
{
	    return m_pBMW;
}

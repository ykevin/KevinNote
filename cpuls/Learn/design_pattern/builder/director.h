
#pragma once
#include "benzmodel.h"
#include "bmwmodel.h"
#include "benzbuilder.h"
#include "bmwbuilder.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CDirector {
	public:
		CDirector();
		~CDirector();
		CBenzModel * GetABenzModel();
		CBenzModel * GetBBenzModel();
		CBMWModel * GetCBMWModel();
		CBMWModel * GetDBMWModel();
	private:
		vector<string> *m_pSeqence;
		CBenzBuilder * m_pBenzBuilder;
		CBMWBuilder * m_pBMWBuilder;
};

CDirector::CDirector(void)
{
	m_pBenzBuilder = new CBenzBuilder();
	m_pBMWBuilder = new CBMWBuilder();
	m_pSeqence = new vector<string>();

}

CDirector::~CDirector(void)
{
	delete m_pBenzBuilder;
	delete m_pBMWBuilder;
	delete m_pSeqence;

}

CBenzModel * CDirector::GetABenzModel()
{
	m_pSeqence->clear();
	m_pSeqence->push_back("start");
	m_pSeqence->push_back("stop");
	m_pBenzBuilder->SetSequence(m_pSeqence);
	return dynamic_cast<CBenzModel*>(m_pBenzBuilder->GetCarModel());

}

CBenzModel * CDirector::GetBBenzModel()
{
	m_pSeqence->clear();
	m_pSeqence->push_back("engine boom");
	m_pSeqence->push_back("start");
	m_pSeqence->push_back("stop");
	m_pBenzBuilder->SetSequence(m_pSeqence);
	return dynamic_cast<CBenzModel*>(m_pBenzBuilder->GetCarModel());

}

CBMWModel * CDirector::GetCBMWModel()
{
	m_pSeqence->clear();
	m_pSeqence->push_back("alarm");
	m_pSeqence->push_back("start");
	m_pSeqence->push_back("stop");
	m_pBMWBuilder->SetSequence(m_pSeqence);
	return static_cast<CBMWModel*>(m_pBMWBuilder->GetCarModel());

}

CBMWModel * CDirector::GetDBMWModel()
{
	m_pSeqence->clear();
	m_pSeqence->push_back("start");
	m_pBenzBuilder->SetSequence(m_pSeqence);
	return dynamic_cast<CBMWModel*>(m_pBMWBuilder->GetCarModel());

}

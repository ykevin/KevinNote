#pragma once

#include "ikindwomen.hpp"

class CWangPo: public IKindWomen {
	public:
		CWangPo(IKindWomen *pKindWomen);
		~CWangPo();
		void HappyWithMan();
		void MakeEyesWithMan();

	private :
		IKindWomen *m_pKindWomen;
};


#pragma once
#include "istrategy.hpp"

class CContext {
	public:
		CContext(IStrategy *pStrategy);
		~CContext();
		void Operate();

	private:
		IStrategy *m_pStrategy;
};

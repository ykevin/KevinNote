#pragma once
#include "istrategy.hpp"

class CBlockEnemy : public IStrategy {
	public:
		CBlockEnemy();
		~CBlockEnemy();
		void Operate();
};

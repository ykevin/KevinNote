#pragma once
#include "istrategy.hpp"

class CGivenGreenLight : public IStrategy {
	public :
		CGivenGreenLight();
		~CGivenGreenLight();
		void Operate();
};


#pragma once
class IStrategy {
	public:
		IStrategy() {} 
		virtual ~IStrategy() {}
		virtual void Operate() = 0;
};

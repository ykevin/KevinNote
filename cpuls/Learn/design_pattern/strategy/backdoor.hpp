
#include "istrategy.hpp"

class CBackDoor : public IStrategy {
	public:
		CBackDoor();
		~CBackDoor();
		void Operate();
};

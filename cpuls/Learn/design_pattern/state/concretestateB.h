#pragma once

#include "state.h"

class ConcreteStateB : public State
{

	public:
		static State * Instance();

		virtual ~ConcreteStateB();

		virtual void handle(Context * c);
	private:
		ConcreteStateB();
		static State * m_pState;
};

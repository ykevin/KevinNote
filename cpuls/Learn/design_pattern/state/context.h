
#pragma once
#include "state.h"

class Context {
	public:
		Context();
		virtual ~Context();

		void changeState(State *st);
		void request();

	private:
		State *m_pState;
};


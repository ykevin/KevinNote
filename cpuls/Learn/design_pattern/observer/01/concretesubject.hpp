
#pragma once

#include "subject.hpp"

class ConcreteSubject : public Subject {
	public:
		ConcreteSubject();
		virtual ~ConcreteSubject();

		virtual int getState();
		virtual void setState(int i);

	private:
		int m_nState;
};

ConcreteSubject::ConcreteSubject()
{
}

ConcreteSubject::~ConcreteSubject()
{
}


int ConcreteSubject::getState()
{
	return m_nState;
}


void ConcreteSubject::setState(int i)
{
	m_nState = i;
}

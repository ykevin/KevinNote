
#pragma once

#include "obeserver.hpp"
#include <vector>

using namespace std;

class Subject {
	public:
		Subject();
		virtual ~Subject();
		Obeserver *m_Oberserver;

		void attach(Obeserver *pObeserver);
		void detach(Obeserver *pObeserver);

		void notify();

		virtual int getState() = 0;
		virtual void setState(int i) = 0;

	private:
		vector<Obeserver *> m_vtObj;
};

Subject::Subject() {}

Subject::~Subject() {}

void Subject::attach(Obeserver *pObeserver) 
{
	m_vtObj.push_back(pObeserver);
}

void Subject::detach(Obeserver *pObeserver)
{
	vector<Obeserver *> :: iterator itr;
	for(itr = m_vtObj.begin(); itr != m_vtObj.end(); itr++) {
		if(*itr == pObeserver) {
			m_vtObj.erase(itr);
			return ;
		}
	}
}


void Subject::notify() {
	vector<Obeserver *> :: iterator itr;
	for(itr = m_vtObj.begin(); itr != m_vtObj.end(); itr++) {
		(*itr)->update(this);
	}
}



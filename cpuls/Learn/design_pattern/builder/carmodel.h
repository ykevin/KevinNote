
#pragma once 
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class CCarModel {
	public:
		CCarModel() {}
		virtual ~CCarModel() {}
		void Run();
		void SetSequence(vector<string> *pSeq);
	protected:
		virtual void Start() = 0;
		virtual void Stop() = 0;
		virtual void Alarm() = 0;
		virtual void EngineBoom() = 0;
	private:
		vector<string> *m_pSequence;
};

void CCarModel::SetSequence(vector<string> *pSeq)
{
	m_pSequence = pSeq;
}

void CCarModel::Run()
{
	vector<string>::const_iterator it = m_pSequence->begin();
	for(; it < m_pSequence->end(); it++){
		string actionName = *it;
		if(actionName.compare("start") == 0)
		{
			Start();
		}

		if(actionName.compare("stop") == 0)
		{
			Stop();
		}

		if(actionName.compare("alarm") == 0)
		{
			Alarm();
		}

		if(actionName.compare("engine boom") == 0)
		{
			EngineBoom();
		}
	}
}

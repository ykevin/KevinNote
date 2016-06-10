
#pragma once
#include "carmodel.h"
#include <iostream>

using namespace std;

class CBenzModel: public CCarModel{
	public:
		CBenzModel();
		~CBenzModel();
	protected:
		void Start();
		void Stop();
		void Alarm();
		void EngineBoom();
};

CBenzModel::CBenzModel()
{

}

CBenzModel::~CBenzModel()
{
	
}

void CBenzModel::Start()
{
	cout << "Benz Start...." << endl;
}

void CBenzModel::Stop()
{
	cout << "Benz Stop..." << endl;
}

void CBenzModel::Alarm()
{
	cout << "Benz Alarm..." << endl;
}

void CBenzModel::EngineBoom()
{
	cout << "Benz EngineBoom..." << endl;
}


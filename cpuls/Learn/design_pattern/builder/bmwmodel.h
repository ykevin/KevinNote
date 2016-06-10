
#pragma once
#include "carmodel.h"
#include <iostream>

using namespace std;

class CBMWModel: public CCarModel{
	public:
		CBMWModel();
		~CBMWModel();
	protected:
		void Start();
		void Stop();
		void Alarm();
		void EngineBoom();
};

CBMWModel::CBMWModel()
{

}

CBMWModel::~CBMWModel()
{
	
}

void CBMWModel::Start()
{
	cout << "BMW Start...." << endl;
}

void CBMWModel::Stop()
{
	cout << "BMW Stop..." << endl;
}

void CBMWModel::Alarm()
{
	cout << "BMW Alarm..." << endl;
}

void CBMWModel::EngineBoom()
{
	cout << "BMW EngineBoom..." << endl;
}


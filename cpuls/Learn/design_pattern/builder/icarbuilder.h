
#pragma once
#include "carmodel.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ICarBuilder {
	public:
		ICarBuilder() { }
		virtual ~ICarBuilder(){ }
		virtual void SetSequence(vector<string> *pSeq) = 0;
		virtual CCarModel *GetCarModel() = 0; 
};

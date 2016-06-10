
#pragma once 
#include "igroup.hpp"
#include <iostream>

using namespace std;

class CRequirementGroup :public IGroup {
	public:
		CRequirementGroup();
		~CRequirementGroup();
		void Find();
		void Add();
		void Delete();
		void Change();
		void Plan();
};

CRequirementGroup::CRequirementGroup() {}

CRequirementGroup::~CRequirementGroup() {}

void CRequirementGroup::Find()
{
	cout << "Find requirement group" << endl;
}

void CRequirementGroup::Add()
{
	cout << "custom add new requirement" << endl;
}

void CRequirementGroup::Delete()
{
	cout << "requirement delete " << endl;
}

void CRequirementGroup::Change()
{
	cout << "Change requirement" << endl;
}

void CRequirementGroup::Plan()
{
	cout << "requirement plan" << endl;
}

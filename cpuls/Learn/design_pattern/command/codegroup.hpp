
#pragma once 
#include "igroup.hpp"
#include <iostream>

using namespace std;

class CCodeGroup :public IGroup {
	public:
		CCodeGroup();
		~CCodeGroup();
		void Find();
		void Add();
		void Delete();
		void Change();
		void Plan();
};

CCodeGroup::CCodeGroup() {}

CCodeGroup::~CCodeGroup() {}

void CCodeGroup::Find()
{
	cout << "Find code group" << endl;
}

void CCodeGroup::Add()
{
	cout << "custom add new code" << endl;
}

void CCodeGroup::Delete()
{
	cout << "code delete " << endl;
}

void CCodeGroup::Change()
{
	cout << "Change code" << endl;
}

void CCodeGroup::Plan()
{
	cout << "code plan" << endl;
}


#pragma once 
#include "igroup.hpp"
#include <iostream>

using namespace std;

class CPageGroup :public IGroup {
	public:
		CPageGroup();
		~CPageGroup();
		void Find();
		void Add();
		void Delete();
		void Change();
		void Plan();
};

CPageGroup::CPageGroup() {}

CPageGroup::~CPageGroup() {}

void CPageGroup::Find()
{
	cout << "Find page group" << endl;
}

void CPageGroup::Add()
{
	cout << "custom add new page" << endl;
}

void CPageGroup::Delete()
{
	cout << "page delete " << endl;
}

void CPageGroup::Change()
{
	cout << "Change page" << endl;
}

void CPageGroup::Plan()
{
	cout << "page plan" << endl;
}

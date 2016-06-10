
#include "igroup.hpp"
#include "codegroup.hpp"
#include "pagegroup.hpp"
#include "requirementgroup.hpp"
#include "invoker.hpp"
#include "addrequirementcommand.hpp"
#include "deletepagecommand.hpp"
#include <iostream>

using namespace std;

void DoIt()
{
	cout << "custome add requirement" << endl;
	IGroup *rg = new CRequirementGroup();
	rg->Find();
	rg->Add();
	rg->Plan();
	delete rg;
	cout << endl;

	cout << "----------客户又想修改一个页面----------" << endl;
	IGroup *pg = new CPageGroup();
	pg->Find();
	pg->Add();
	pg->Plan();
	delete pg;
	cout << endl;

	cout << "----------客户又想删除一个功能----------" << endl;
	IGroup *cg = new CCodeGroup();
	cg->Find();
	cg->Add();
	cg->Plan();
	delete cg;
	cout << endl;
}

void DoNew()
{
	cout << "----------客户觉得烦了，希望只找一个人，并告诉他要做什么----------" << endl;
	cout << "----------客户要求增加一项需求----------" << endl;
	CInvoker gary;
	ICommand *pcommand = new CAddRequirementCommand();
	gary.SetCommand(pcommand);
	gary.Action();
	delete pcommand;
	cout << endl;

	// 客户想要改动只需要找CInvoker就可以了。
	cout << "----------客户要求删除一个页面----------" << endl;
	CInvoker ricky;
	ICommand *pcommand2 = new CDeletePageCommand();
	ricky.SetCommand(pcommand2);
	ricky.Action();
	delete pcommand2;
	cout << endl;
}

int main()
{
	DoIt();
	DoNew();
	return 0;
}

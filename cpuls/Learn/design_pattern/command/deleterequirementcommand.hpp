
#pragma once
#include "icommand.h"
class CDeletePageCommand :
	public ICommand
{
	public:
		CDeletePageCommand(void);
		~CDeletePageCommand(void);
		void Execute();
};

CDeletePageCommand::CDeletePageCommand(void)
{

}

CDeletePageCommand::~CDeletePageCommand(void)
{

}

void CDeletePageCommand::Execute()
{
	//执行增另一项需求的命令
	this->ICommand::m_ppg->Find();

	//增加一份需求
	this->ICommand::m_ppg->Delete();

	//给出计划
	this->ICommand::m_ppg->Plan();
}

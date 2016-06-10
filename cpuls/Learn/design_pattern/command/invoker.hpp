
#pragma once
#include "icommand.hpp"

class CInvoker {
	public :
		CInvoker();
		~CInvoker();
		void SetCommand(ICommand *pcommand);
		void Action();
	private:
		ICommand *m_pCommand;
};

CInvoker::CInvoker() {}

CInvoker::~CInvoker() {}

void CInvoker::SetCommand(ICommand *pcommand)
{
	this->m_pCommand = pcommand;
}

void CInvoker::Action()
{
	this->m_pCommand->Execute();
}


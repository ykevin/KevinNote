
#pragma once 
#include "requirementgroup.hpp"
#include "pagegroup.hpp"
#include "codegroup.hpp"

class ICommand {
	public:
		ICommand()
		{
			m_prg = new CRequirementGroup();
			m_ppg = new CPageGroup();
			m_pcg = new CCodeGroup();
		} 

		virtual ~ICommand()
		{
			delete m_prg;
			delete m_ppg;
			delete m_pcg;
		}

		virtual void Execute() = 0;

	protected:
		CRequirementGroup *m_prg;
		CPageGroup *m_ppg;
		CCodeGroup *m_pcg;
};


#pragma once 
#include "letterprocess.h"
#include "letterprocessimpl.h"
#include "letterpolice.h"

class ModernPostOffice
{
	public:
		ModernPostOffice();
		~ModernPostOffice();
		void SendLetter(string context, string address);
	private:
		LetterProcess *m_pLetterProcess;
		LetterPolice *m_pLetterPolice;
};

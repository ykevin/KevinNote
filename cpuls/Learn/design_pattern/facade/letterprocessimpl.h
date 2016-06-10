
#pragma once

#include "letterprocess.h"

class LetterProcessImpl : public LetterProcess{
	public:
	   	LetterProcessImpl();
		~LetterProcessImpl();

		void WriteContext(string context);
		void FillEnvelope(string address);
		void LetterIntoEnvelope();
		void SendLetter();
};

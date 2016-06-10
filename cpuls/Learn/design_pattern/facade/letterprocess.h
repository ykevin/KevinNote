#pragma once

#include <iostream>

using namespace std;

class LetterProcess {
	public:
		LetterProcess();
		virtual ~LetterProcess();
		virtual void WriteContext(string context) = 0;
		virtual void FillEnvelope(string address) = 0;
		virtual void LetterIntoEnvelope() = 0;
		virtual void SendLetter() = 0;
};



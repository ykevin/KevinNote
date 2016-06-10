
#include "letterprocessimpl.h"
#include <iostream>

using namespace std;

LetterProcessImpl::LetterProcessImpl()
{

}

LetterProcessImpl::~LetterProcessImpl()
{

}

void LetterProcessImpl::WriteContext(string context)
{
	cout << "请填写信的内容:" << context << endl;
}

void LetterProcessImpl::FillEnvelope(string address)
{
	cout << "请填写收人地址及姓名:" << address << endl;
}

void LetterProcessImpl::LetterIntoEnvelope()
{
	cout << "把信放到信封中....."<< endl;
}

void LetterProcessImpl::SendLetter()
{
	cout << "邮递信件..."<< endl;
}



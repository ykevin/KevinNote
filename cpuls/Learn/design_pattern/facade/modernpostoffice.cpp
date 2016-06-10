#include "modernpostoffice.h"

ModernPostOffice::ModernPostOffice()
{
	this->m_pLetterProcess = new LetterProcessImpl();
	this->m_pLetterPolice = new LetterPolice();
}

ModernPostOffice::~ModernPostOffice()
{
	delete m_pLetterProcess;
	delete m_pLetterPolice;
}

void ModernPostOffice::SendLetter( string context, string address  )
{
	//帮忙写信
	m_pLetterProcess->WriteContext(context);
	//写好信封
	m_pLetterProcess->FillEnvelope(address);
	//警察要检查信件了
	m_pLetterPolice->CheckLetter(m_pLetterProcess);
	//把信放到信封中
	m_pLetterProcess->LetterIntoEnvelope();
	//邮递信件
	m_pLetterProcess->SendLetter();

}


#include "emperor.h"
#include <iostream>

using namespace std;

CEmperor *CEmperor::m_pEmperor = NULL;
HANDLE CEmperor::m_pMutex = CreateMutex(NULL, FALSE, NULL);
CEmperor::CGarbo CEmperor::m_Garbo;
CEmperor::CEmperor()
{
	cout << "Create CEmperor Instance" << endl;
}

CEmperor::~CEmperor()
{
	cout << "destory CEmperor Instance" << endl;
}

void CEmperor::EmperorInfo()
{
	char msgBuffer[50] = {0};
	sprintf_s(msgBuffer, 50, "皇帝XXXXXX.....%(s)", m_EmperorTag.c_str());
	string msg(msgBuffer);
	cout << msg.c_str() << endl;
}

CEmperor *CEmperor::GetInstance()
{
	if(NULL == m_pEmperor)
	{
		WaitForSingleObject(m_pMutex, INFINITE);
		if(NULL == m_pEmperor)
			m_pEmperor = new CEmperor();
		ReleaseMutex(m_pMutex);
	}

	return m_pEmperor;
}

void CEmperor::ReleaseInstance()
{
	if (NULL != m_pEmperor)
	{
		WaitForSingleObject(m_pMutex, INFINITE);
		if (NULL != m_pEmperor)
		{
			delete m_pEmperor;
			m_pEmperor = NULL;

		}
		ReleaseMutex(m_pMutex);

	}
}

void CEmperor::SetEmperorTag( string tag  )
{
	m_EmperorTag = tag;
}

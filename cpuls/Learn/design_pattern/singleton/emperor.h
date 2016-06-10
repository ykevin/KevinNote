
#pragma once
#include <iostream>

using namespace std;

class CEmperor {
	public:
		static CEmperor *GetInstance();
		static void ReleaseInstance();
		void EmperorInfo();
		void SetEmperorTag(string tag);
	private:
		CEmperor();
		virtual ~CEmperor();
		CEmperor(const CEmperor&);
		CEmperor& operator=(const CEmperor &);
		static CEmperor *m_pEmperor;
		static HANDLE m_pMutex;
		string m_EmperorTag;
		class CGarbo {
			public:
				CGarbo()
				{
					cout << "Create Grabo" << endl;
				}

				~CGarbo()
				{
					cout << "Destroy Garbo" << endl;
					if(NULL != m_pEmperor)
					{
						WaitForSingleObject(m_pMutex INFINITE);
						if(NULL != m_pEmperor)
						{
							cout << "Remove instance" << endl;
							delete m_pEmperor;
							m_pEmperor = NULL;
						}
						ReleaseMutex(m_pMutex);
					}
					if(NULL != m_pMutex)
					{
						cout << "Delete mutex" << endl;
						CloseHandle(m_pMutex);
						m_pMutex = NULL;
					}
				}
		};
		static CGarbo m_Garbo;
};



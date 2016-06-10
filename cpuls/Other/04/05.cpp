#include <iostream>
#include <cstring>

using namespace std;

class Person {
	char *pName;
	//string *pName;
public :
	Person(const char * pN = "no name"){
		cout << "constructing " << pN <<endl;
		pName = new char[strlen(pN) + 1];
		if(pName)
			strcpy(pName, pN);
			//memcpy(pName, pN, strlen(pN) + 1);
	}

	Person(const Person &s){
		cout << "copy constructing " << s.pName <<endl;
		pName = new char[strlen(s.pName) + 1];
		if(pName)
			strcpy(pName, s.pName);
			//memcpy(pName, pN, strlen(pN) + 1);
	}

	~Person(){
		cout << "destructing " << pName << endl;
		delete[] pName;
	}
};

int main()
{
	Person p1("Randy");
	Person p2(p1);
	//Person p2;
}

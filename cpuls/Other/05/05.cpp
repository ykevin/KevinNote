
#include <iostream>
#include <cstring>

using namespace std;

class Person {
	char *pName;
public :
	Person(const char *pN = "no name") {
		cout << "constructor " << pN << endl;
		pName = new char[strlen(pN) + 1];
		if(pName)
			strcpy(pName, pN);
	}
	
	Person (const Person &s) {
		cout << "copy constructor " << s.pName <<  endl;
		pName = new char[strlen(s.pName) + 1];
		if(pName)
			strcpy(pName, s.pName);
	}
	Person & operator = (Person &s) {
		cout << "assigning " << s.pName << endl;
		if(this == &s)
			return s;
		//delete [] pName;
		pName = new char[strlen(s.pName) + 1 ];
		if(pName)
			strcpy(pName, s.pName);

		return *this;
	}
	~Person(){
		cout << "desconstructor " << pName << endl;
		delete[] pName;
	}
};

int main ()
{
	Person p1("kevin");
	Person p2("ellie");
	p2 = p1;
	return 0;
}

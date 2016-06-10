
#include <iostream>

using namespace std;

class StudentID {
	int value;
public :
	StudentID (int id = 0){
		value = id;
		cout << "Assigning student id " << value << endl;
	}
};

class Student {
	string name;
	StudentID id;
public :
	Student(string n = "no name", int ssID = 0) : id(ssID), name(n){
		cout << "Constructing student " << n << endl;
	}
};

int main() {
	Student s("Randy", 98);
	Student t("kevin");
}

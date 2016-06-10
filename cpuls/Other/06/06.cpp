
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Vector {
	int size;
	int *buffer;

public :
	Vector(int s=20) ;
	Vector(const Vector &v);
	Vector& operator = (Vector &v){
		cout << "assign constructor func!" << endl;
		if(this == &v)
			return v;
		buffer = new int[size=v.size];
		for(int i = 0; i < v.size; i++)
			buffer[i] = v.buffer[i];
		return *this;
	}
	int &elem(int ndx);
	void display();
	void set();
	~Vector();
};


Vector::Vector(int s) {
	cout << "constructor func!" << endl;
	buffer = new int[size=s];
	for(int i = 0; i < size; i++)
		buffer[i] = i * i;
}

Vector::Vector(const Vector &v)
{
	cout << "copy constructor func!" << endl;
	buffer = new int[size=v.size];
	for(int i = 0; i < v.size; i++)
		buffer[i] = v.buffer[i];
}
/*
Vector::Vector& operator = (Vector &v){
	if(this == &v)
		return v;
	buffer = new int[v.size];
	for(int i = 0; i < v.size; i++)
		buffer[i] = i;
	return *this;
}	
*/

int& Vector::elem(int ndx) {
	if(ndx < 0 || ndx >= size) {
		cout << "error index!" << endl;
		exit(1);
	}
	return buffer[ndx];
}

void Vector::display() {
	cout << "Vector display !" << endl;
	for(int i = 0; i < size; i++)
		cout << buffer[i] << endl;
}

void Vector::set() {
	cout << "Vector set !" << endl;
	for(int i = 0; i < size; i++)
		buffer[i] = i + 1;
}

Vector::~Vector() {
	delete[] buffer;
}

int main()
{
   Vector a(10);
   //Vector b(a);
   Vector b;
   //a.set();
   b=a;
   b.display();
}

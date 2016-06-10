
#include <iostream>

using namespace std;

class A {
	int x;
	public :
		A( int a) : x(a) { cout << " Constructing A\n"; }
};

class B : public A {
	public :
		B() { cout << "Constructing B\n "; }
};

int main ()
{
	B b;
}	

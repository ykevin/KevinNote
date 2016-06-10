#include<iostream>

using namespace std;

class A
{
	public:
		void func()
		{cout << "a.func" << endl;}
};
class B
{ 
	public:
		void func()
		{cout << "b.func" <<endl;}
		void gunc()
		{cout << "b.gunc" << endl;}
};
class C:public A,public B
{
	public:
		void gunc()
		{cout<<"c.gunc"<<endl;}
		void hunc(){A::func();}
};

int main()
{
	C obj;
	obj.A::func();
	obj.B::func();
	obj.C::gunc();
	obj.gunc();//obj.C::gunc()
	obj.hunc();

	return 0;
}


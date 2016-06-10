
#include<iostream>

using namespace std;

class A
{
	public:
		void setA(int x){a=x;}
		void showA(){cout<<"a="<<a<<endl;}
	private:
		int a;
};
class B
{
	public:
		void setB(int x){b=x;}
		void showB(){cout<<"b="<<b<<endl;}
	private:
		int b;
};

class C:public A,private B
{
	public:
		void setC(int x,int y){c=x;setB(y);}
		void showC()
		{ showB();cout<<"c="<<c<<endl; }     
	private:
		int c; };
int main()
{
	C obj;
	obj.setA(53);
	obj.showA();
	obj.setC(55,58);
	obj.showC();

	return 0;
}


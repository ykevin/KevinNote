
#include <iostream>

using namespace std;

int main(void)
{
	int x = 10, y = 15;
	int z = [=]()mutable{ int n = x + y; x = y; y = n; return n; }();
	cout << "z : " << z << endl;
	cout << "x : " << x << " y : " << y;
	return 0;
}


#include <iostream>

using namespace std;

int main(void)
{
	auto f = [](int x, int y){ return x + y; };
	cout << "f : " << f(32, 44) << endl;
	return 0;
}


#include <iostream>

using namespace std;

int main(void)
{
	int n = [](int x, int y){ return x + y; }(4, 5);
	cout << "n : " << n << endl;
	return 0;
}

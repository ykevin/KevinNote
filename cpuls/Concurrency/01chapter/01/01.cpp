#include <iostream>
#include <thread>

using namespace std;


void hello()
{
	cout << "Hello World!" << endl;
}

int main(void)
{
	std::thread t(hello);
	t.join();
}

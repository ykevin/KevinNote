
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void do_something(int &i)
{
	cout << "Hello World " << i << endl;
}

struct func {
	int& i;
	func(int& i_):i(i_){}

	void operator()()
	{
		for(unsigned j = 0; j < 10; ++j)
			do_something(i);
	}
};

void oops()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread my_thread(my_func);
	//usleep(10000);
	my_thread.detach();
	//my_thread.join();
}


int main()
{
	oops();
	return 0;
}

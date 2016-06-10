
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void do_something(int &i)
{
	cout << "Hello World " << i++ << endl;
	usleep(1000000);
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

void do_something_in_current_thread()
{
	cout << "do_something_in_current_thread " << endl;
}

void f()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread my_thread(my_func);
	try {
		do_something_in_current_thread();
	}
	catch(...)
	{
		my_thread.join();
		throw;	
	}

	my_thread.join();
}


int main()
{
	f();
	return 0;
}

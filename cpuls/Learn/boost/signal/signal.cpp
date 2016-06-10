
#include <iostream>
#include <string>
#include <boost/signal.hpp>

void print_sum(float x, float y)
{
	std::cout << "The sum is " << x + y << std::endl;
}

void print_product(float x, float y)
{
	std::cout << "The product is " << x*y << std::endl;
}

int main()
{
	boost::signal<void(float, float)> sig;
	sig.connect(print_sum);
	sig.connect(print_product);

	sig(3, 5);
}

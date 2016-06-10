
#include <iostream>
#include <type_traits>

int main()
{
	std::cout << std::is_same<int, int>::value << std::endl;
	std::cout << std::is_same<int, unsigned int>::value << std::endl;
	std::cout << std::is_same<int, signed int>::value << std::endl;

	return 0;
}

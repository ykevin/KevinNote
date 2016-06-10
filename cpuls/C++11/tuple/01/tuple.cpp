#include <iostream>
#include <map>
#include <tuple>
#include <string>
 
int main()
{
	std::map<int, std::string> m;

	auto r = m.emplace(std::piecewise_construct,
			std::forward_as_tuple(5),
			std::forward_as_tuple("kevin is ok!"));
	std::cout << "m[10] = " << m[10] << '\n';
	std::cout << "m[20] = " << r.first->second << '\n';

	// The following is an error: it produces a
	// std::tuple<int&&, char&&> holding two dangling references.
	//
	// auto t = std::forward_as_tuple(20, 'a');
	// m.emplace(std::piecewise_construct, std::forward_as_tuple(10), t);

}

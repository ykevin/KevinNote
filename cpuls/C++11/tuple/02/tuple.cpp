#include<iostream>
#include<tuple>

using namespace std;

int main()
{
	std::tuple<int, std::string, float> t1(10, "test", 3.14);
	int n = 7;
	auto t2 = std::tuple_cat(t1, std::make_pair("Foo", "bar"), t1, std::tie(n));
	n = 10;
	cout << "int : "<< get<0>(t2);
}

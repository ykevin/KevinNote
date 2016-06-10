
#include <iostream>
#include <fstream>
#include <cassert>
#include <jsoncpp/json/json.h>

using namespace std;

int main(void)
{
	ifstream input;
	input.open("test.json");
	assert(input.is_open());

	Json::Reader reader;
	Json::Value root;
	if(!reader.parse(input, root, false))
		return -1;

	string name = root["name"].asString();
	int age = root["age"].asInt();

	cout << "name : " << name << endl;;
    cout << "age : " << age << endl;	

	return 0;
}


#include <iostream>
#include <fstream>
#include <cassert>
#include <jsoncpp/json/json.h>

using namespace std;

int main(void)
{
	ifstream input;
	input.open("./signtx.json");
	assert(input.is_open());

	Json::Reader reader;
	Json::Value root;
	if(!reader.parse(input, root, false)) {
		cout << "json parse fail" << endl;
		return -1;
	}

    cout << "root : " << root.toStyledString() << endl;	
	/*
	string type = root["type"].asString();
	Json::Value msg = root["message"];

	cout << "type : " << type << endl;;
    cout << "msg : " << msg.toStyledString() << endl;	
	cout << "request_type: " << msg["request_type"].asString() << endl;

	Json::Value sub_msg = msg["details"];
    cout << "sub_msg : " << sub_msg.toStyledString() << endl;	
    cout << "tx_hash : " << sub_msg["tx_hash"].asString() << endl;	
*/
	return 0;
}

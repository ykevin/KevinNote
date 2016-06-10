
#include <iostream>
#include <jsoncpp/json/json.h>

using namespace std;

int main()
{
	Json::Value json_msg, msg, sub_msg;
	json_msg["type"] = Json::Value("TxAck");
	sub_msg["prev_hash"] = Json::Value("44bd70d901b76dfc07bc76eede4b0a0f28e145d5f9baf27f3ee414e87bf1ace5");
	sub_msg["prev_index"] = Json::Value(0);
	sub_msg["address_n"].append(2147483692);
	sub_msg["address_n"].append(214);
	sub_msg["address_n"].append(2147);
	sub_msg["address_n"].append(1);
	sub_msg["address_n"].append(2);
	//msg["input"] = Json::Value(sub_msg);
	msg["input"].append(sub_msg);
	json_msg["message"] = Json::Value(msg);

	cout << json_msg.toStyledString() << endl;

	return 0;
}

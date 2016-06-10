#include <stdio.h>
#include <curl/curl.h>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <jsoncpp/json/json.h>

using namespace std;


void print_json_data(const Json::Value &val)
{
	switch(val.type()) {
		case Json::nullValue :
			cout << "unknown type= " << val.type()<< endl;
			break;
		case Json::stringValue:
			cout << "string(" << val.asString().c_str() << ")";
			break;
		case Json::intValue :
			cout << "int(" << val.asInt() << ")";
			break;
		case Json::uintValue :
			cout << "uint(" << val.asUInt() << ")";
			break;
		case Json::booleanValue :
			cout << "bool(" << val.asBool() << ")";
			break;
		case Json::realValue :
			cout << "double(" << val.asDouble() << ")";
			break;
		default :
			break;
	}
}

bool print_json_tree(Json::Value const &root, int depth)
{
	depth += 1;
	cout << "{type=" << root.type()<< " , size=" << root.size() << "}";

	if( root.size() > 0  ) {
		cout << endl;
		for( Json::ValueIterator itr = root.begin() ; itr != root.end() ; itr++  ) {
			// Print depth. 
			for( int tab = 0 ; tab < depth; tab++ ) {
				cout << "-";
			}
			cout << " subvalue(";
			print_json_data(itr.key());
			cout << ") -";
			print_json_tree(*itr, depth ); 
		}
		return true;
	} else {
		cout << " ";
		print_json_data(root);
		cout << endl;
	}
	return true;
}

void parse_json_data(string const &data)
{
	std::istringstream jsonIStream;
	jsonIStream.str(data);
	Json::Reader reader;
	Json::Value root;
	if(!reader.parse(data, root, false)) {
		cout << "json parse fail" << endl;
		return ; 
	} 

	cout << "josn " << root.toStyledString() << endl;
	cout << "vin.txid: " << root["vin"][0]["txid"] << endl;
	cout << "vin.hex: " << root["vin"][0]["scriptSig"]["hex"] << endl;
	cout << "vout.value: " << root["vout"][0]["value"] << endl;
	cout << "size : " << root["vout"].size() << endl;
	//print_json_tree(root, 0);
}

size_t receive_data(void* buffer, size_t size, size_t nmemb, void* userp)
{
	std::string json_data;

	json_data = static_cast<char *>(buffer);
//	cout << "json_data : " << endl << json_data << endl;

	int temp = *(int*)userp;    // 这里获取用户自定义参数
	parse_json_data(json_data);

	return nmemb;
}

int main(void)
{
	CURL *curl;
	CURLcode res;

	int my_param = 1;
	
	try{
		curl = curl_easy_init();
		if(curl) {
			curl_easy_setopt(curl, CURLOPT_URL, "https://insight.bitpay.com/api/tx/c6091adf4c0c23982a35899a6e58ae11e703eacd7954f588ed4b9cdefc4dba52");
			// 设置接收到HTTP服务器的数据时调用的回调函数
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, receive_data);
			// 设置自定义参数(回调函数的第四个参数)
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &my_param);
			// 执行一次URL请求
			res = curl_easy_perform(curl);
			/* Check for errors */ 
			if(res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
			/* always cleanup */ 
			curl_easy_cleanup(curl);
		}

	} catch (std::exception const& e) {
		cerr << e.what() << endl;	
	}
	return 0;
}

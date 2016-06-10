
#include <iostream>
#include <google/protobuf/message.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>

#include "config.pb.h"

using namespace std;
using namespace google::protobuf;

int main(void)
{
	Configuration c;
	DescriptorPool descriptor_pool;
	
	c.IsInitialized();
	FileDescriptorSet set = c.wire_protocol();
	cout << "file_size: "<< set.file_size() << endl;
	for(int i = 0; i < set.file_size(); i++) {
		cout << "fun" << endl;
		descriptor_pool.BuildFile(set.file(i));
	}

	return 0;
}

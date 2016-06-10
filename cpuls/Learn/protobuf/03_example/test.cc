
#include <iostream>
#include <string>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include "user.pb.h"

using namespace std;

using namespace google::protobuf; 

Message* createMessage(const string &typeName) {
	Message *message = NULL;
	const Descriptor *descriptor = DescriptorPool::generated_pool()->FindMessageTypeByName(typeName);
	if(descriptor) {
		const Message *prototype = MessageFactory::generated_factory()->GetPrototype(descriptor);
		if(NULL != prototype)
			message = prototype->New();
	}

	return message;
}


int main(void)
{
	Message *msg = createMessage("user.UserInfo");

	if(NULL == msg)
		return -1;
	const Descriptor *descriptor = msg->GetDescriptor();
	const Reflection *reflection = msg->GetReflection();

	const FieldDescriptor *idField = descriptor->FindFieldByName("id");
	if(idField != NULL){
		cout << "set id value!" << endl;
		reflection->SetInt64(msg, idField, 100);
	}

	delete msg;
	return 0;
}

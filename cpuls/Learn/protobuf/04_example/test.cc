
#include <iostream>
#include <string>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include "messages.pb.h"
#include "storage.pb.h"
#include "types.pb.h"

using namespace std;

using namespace google::protobuf; 

int main(void)
{
	static const std::string enum_name = "MessageType";
	static const std::string enum_prefix = "MessageType_";
	typedef std::map<int, Descriptor const *> id_map;
	id_map descriptor_index;

	auto desp = DescriptorPool::generated_pool()->FindEnumTypeByName(enum_name);

	if(!desp)
		throw std::invalid_argument("invalid file descriptor set!");
	
	for(int i = 0;  i < desp->value_count(); i++){
		auto ev = desp->value(i);
		auto name = ev->name().substr(enum_prefix.size());
		descriptor_index[ev->number()] = DescriptorPool::generated_pool()->FindMessageTypeByName(name);
	}

	string name;
	for(auto &kv : descriptor_index) {
		if(kv.second->name() == "Features")
		{
			cout << "find name index : " << kv.first << endl;
			name = kv.second->name();	
		}

	}

	const Descriptor *descriptor = DescriptorPool::generated_pool()->FindMessageTypeByName(name);
	const Message *prototype =  MessageFactory::generated_factory()->GetPrototype(descriptor);
	Message *msg = prototype->New();

	const Descriptor *desc = msg->GetDescriptor();
	const Reflection *reflection = msg->GetReflection();

	cout << "cout : " << desc->field_count() << endl;
	for(int i = 0; i < desc->field_count(); i++){
		auto fd = desc->field(i);
		cout << "fname :" << fd->name() << endl;	
	}

/*
	const FieldDescriptor *idFieled = desc->FindFieldByName("delay_time");
	if(idFieled != NULL){
		cout << "set delay_time" <<endl;
		reflection->SetUInt32(msg, idFieled, 10);
	}
	*/
	return 0;
}

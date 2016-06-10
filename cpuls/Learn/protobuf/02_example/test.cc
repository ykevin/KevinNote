
#include <iostream>
#include <string>
#include <cassert>
#include <google/protobuf/message.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>

#include "test.pb.h"

using namespace google::protobuf;
using namespace std;

int main(void)
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	string data;
	{

		Foo foo;
		foo.set_text("Hello World!");
		foo.add_numbers(1);
		foo.add_numbers(5);
		foo.add_numbers(42);
		foo.SerializeToString(&data);
		cout << "ch : ";
		for(auto ch : data)
			printf("0x%x ", ch);
		cout << endl;
	}

	{
		Foo foo;	
		foo.ParseFromString(data);

		assert(foo.text() == "Hello World!");
		assert(foo.numbers_size() == 3);
		assert(foo.numbers(0) == 1);
		assert(foo.numbers(1) == 5);
		assert(foo.numbers(2) == 42);

	}
	
	
	{
		Message* foo = new Foo;
		const Descriptor* descriptor = foo->GetDescriptor();
		const FieldDescriptor* text_field = descriptor->FindFieldByName("text");
		assert(text_field != NULL);
		assert(text_field->type() == FieldDescriptor::TYPE_STRING);
		assert(text_field->label() == FieldDescriptor::LABEL_OPTIONAL);
		const FieldDescriptor* numbers_field = descriptor->FindFieldByName("numbers");
		assert(numbers_field != NULL);
		assert(numbers_field->type() == FieldDescriptor::TYPE_INT32);
		assert(numbers_field->label() == FieldDescriptor::LABEL_REPEATED);

		foo->ParseFromString(data);

		// Use the reflection interface to examine the contents.
		const Reflection* reflection = foo->GetReflection();
		assert(reflection->GetString(*foo, text_field) == "Hello World!");
		assert(reflection->FieldSize(*foo, numbers_field) == 3);
		assert(reflection->GetRepeatedInt32(*foo, numbers_field, 0) == 1);
		assert(reflection->GetRepeatedInt32(*foo, numbers_field, 1) == 5);
		assert(reflection->GetRepeatedInt32(*foo, numbers_field, 2) == 42);
		delete foo;

	}


	return 0;
}

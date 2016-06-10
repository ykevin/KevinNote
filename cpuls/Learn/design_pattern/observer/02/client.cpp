
#include <iostream>
#include "observer.hpp"
#include "concreteobserver.hpp"

int main()
{
	Blog *blog = new BlogCSDN("wuzhekai1985");
	Observer *observer1 = new ObserverBlog("tutupig", blog);
	blog->Attach(observer1);
	blog->SetStatus("发表设计模式C++实现（15）——观察者模式");
	blog->Notify();
	delete blog; delete observer1;
	return 0;
}

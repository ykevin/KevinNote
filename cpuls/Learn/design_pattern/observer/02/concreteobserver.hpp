
#pragma once

#include "observer.hpp"
#include <iostream>
#include <list>

using namespace std;

//具体博客类
class BlogCSDN : public Blog
{
	private:
		string m_name; //博主名称
	public:
		BlogCSDN(string name): m_name(name) {}
		~BlogCSDN() {}
		void SetStatus(string s) { m_status = "CSDN通知 : " + m_name + s;  } //具体设置状态信息
		string GetStatus() { return m_status;  }
};
//具体观察者
class ObserverBlog : public Observer   
{
	private:
		string m_name;  //观察者名称
		Blog *m_blog;   //观察的博客，当然以链表形式更好，就可以观察多个博客
	public: 
		ObserverBlog(string name,Blog *blog): m_name(name), m_blog(blog) {}
		~ObserverBlog() {}
		void Update()  //获得更新状态
		{ 
			string status = m_blog->GetStatus();
			cout<<m_name<<"-------"<<status<<endl;
		}
};

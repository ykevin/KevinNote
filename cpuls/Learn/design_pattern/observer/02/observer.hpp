
#pragma once

#include <list>
#include <string>

using namespace std;

//观察者
class Observer  
{
	public:
		Observer() {}
		virtual ~Observer() {}
		virtual void Update() {} 
};

//博客
class Blog  
{
	public:
		Blog() {}
		virtual ~Blog() {}
		void Attach(Observer *observer) { m_observers.push_back(observer);  }	 //添加观察者
		void Remove(Observer *observer) { m_observers.remove(observer);  }        //移除观察者
		void Notify() //通知观察者
		{
			list<Observer*>::iterator iter = m_observers.begin();
			for(; iter != m_observers.end(); iter++)
				(*iter)->Update();
		}
		virtual void SetStatus(string s) { m_status = s;  } //设置状态
		virtual string GetStatus() { return m_status;  }    //获得状态
	private:
		list<Observer* > m_observers; //观察者链表
	protected:
		string m_status; //状态
};

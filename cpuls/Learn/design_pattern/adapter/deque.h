
#pragma once
#include <iostream>

using namespace std;

class Deque {
	public:
		void push_back(int x) { cout << "Deque push_back" << endl;  }
		void push_front(int x) { cout << "Deque push_front " << endl; }
		void pop_back() { cout << "Deque pop_back" << endl; }
		void pop_front() { cout << "Deque pop_front" << endl; }
};

class Sequence {
	public:
		virtual void push(int x) = 0;
		virtual void pop () = 0;
};

class Stack: public Sequence
{
	public:
		void push(int x) { deque.push_back(x); }
		void pop() {deque.pop_back();}
	private:
		Deque deque;
};

class Queue:public Sequence {
	public:
		void push(int x) {deque.push_back(x);}
		void pop() {deque.pop_front();}
	private:
		Deque deque;
};



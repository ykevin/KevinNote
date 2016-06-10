
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

using namespace std;

template <typename T>

class threadsafe_queue {
	private :
		mutable std::mutex mut;
		std::queue<T> data_queue;
		std::condition_variable data_cond;
	public:
		threadsafe_queue() {}

		void wait_and_pop(T &value)
		{
			std::unique_lock<std::mutex> lk(mut);
			data_cond.wait(lk, [this]{ return !data_queue.empty();});
			value = std::move(*data_queue.front());
			data_queue.pop();
		}

		std::shared_ptr<T> wait_and_pop()
		{
			std::unique_lock<std::mutex> lk(mut);
			data_cond.wait(lk, [this]{return !data_queue.empty();});
			std::shared_ptr<T> res = data_queue.front();
			data_queue.pop();
			return res;
		}

		bool try_pop(T &value)
		{
			std::lock_guard<std::mutex> lk(mut);
			if(data_queue.empty())
				return false;
			value = std::move(*data_queue.front());
			data_queue.pop();
			return true;
		}

		std::shared_ptr<T> try_pop() 
		{
			std::lock_guard<std::mutex> lk(mut);
			if(data_queue.empty())
				return std::shared_ptr<T> ();
			std::shared_ptr<T> res = data_queue.front();
			data_queue.pop();
			return res;
		}

		void push(T new_value)
		{
			std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
			std::lock_guard<std::mutex> lk(mut);
			data_queue.push(data);
			data_cond.notify_one();
		}

		bool empty() const
		{
			std::lock_guard<std::mutex> lk(mut);
			return data_queue.empty();
		}

};

int main()
{
	threadsafe_queue<int> si;
	si.push(5);
	si.wait_and_pop();
	if(!si.empty())
	{
		cout << "pop is operator" << endl;
	//	int x;
	//	si.try_pop(x);
	//	cout << "x : " << x << endl;
		auto a = si.try_pop();
		cout << "a : " << *a << endl; 
	}

	return 0;
}

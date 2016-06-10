#include <boost/thread/future.hpp>
#include <boost/thread.hpp>
#include <boost/optional.hpp>
#include <boost/utility/result_of.hpp>
#include <unistd.h>


int add(int a, int b)
{
	//static const auto sleep_time = boost::chrono::seconds(3);
	//boost::this_thread::sleep_for(sleep_time);
	return (a + b);
}

template<typename result_type, typename fun>
//boost::optional<result_type> GetFuture(fun f)
int32_t GetFuture(fun f)
{
	boost::packaged_task<result_type> add_task(f);
	boost::unique_future<result_type> add_result = add_task.get_future();

	boost::thread work_thread(boost::move(add_task));
	if (!add_result.timed_wait(boost::posix_time::milliseconds(2000)))
	{
		return 0;
		//return boost::optional<result_type>(boost::none);
	}

	work_thread.join();

	if (add_result.is_ready() && add_result.has_value())
	{
		std::cout << "add_result: " << add_result.get() << std::endl;
		return add_result.get();
	}
	else
	{
		return 0;
		//return boost::optional<result_type>(boost::none);
	}

}

void Test_BoostFuture()
{
	//boost::optional<boost::int32_t>res =  GetFuture<boost::int32_t>(boost::bind(&add, 3, 5));
	auto res =  GetFuture<boost::int32_t>(boost::bind(&add, 3, 5));
	if(res) 
		std::cout << "thread ok ......res: " << res << std::endl;
	else
		std::cout << "thread fail .......res " << res << std::endl;
};

int main()
{
	Test_BoostFuture();

	return 1;
}


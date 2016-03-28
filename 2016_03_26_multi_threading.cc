#include <iostream>

#include <atomic>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>
#include <vector>
#include <queue>

#include <ctime>
using std::cout;
using std::endl;
using std::cin;

std::mutex mtx;

void job1()
{
	auto mod = [](int i, int j){return i % j; };

	mtx.lock();
	cout << "****1****" <<endl;
	cout<< std::this_thread::get_id() <<endl;
	cout << "1" << " mod : "<< mod(100, 9) << endl;
	mtx.unlock();
}


void job2(int i)
{
	//lock_guard 对象通常用于管理某个锁(Lock)对象
	std::lock_guard<std::mutex> lck(mtx);
	cout << "****2****" <<endl;
	cout<< std::this_thread::get_id() <<endl;
	for (int i = 5; i < 10; i++)
		cout << i <<" ";
	cout<<endl;
}	

void job3()
{
	//std::unique_lock<std::mutex> lock {m_task};
	std::unique_lock<std::mutex> lck(mtx);
	cout << "****3****" <<endl;
	cout<< std::this_thread::get_id() <<endl;
	for (int i=0; i<10; ++i) {
		cout << "k";
	}cout << '\n';
}

void test_thread()
{
	std::thread first(job1);
	//sleep(2);
	std::thread second(job2, 2);
	std::thread third(job3);
	// synchronize threads:
	first.join();// pauses until first finishes
	second.join();// pauses until second finishes
	third.join();

	cout<< std::this_thread::get_id() <<endl;
}


void thread_pool()
{
	using Task = std::function<void()>;
	std::vector<std::thread> pool;
	std::queue<Task> tasks;
}

void atomic_use()
{
	std::atomic<bool> stop{false};
	stop.store(true);
	cout << "stop: "<<stop.load()<<endl;
}

int main()
{
	atomic_use();
	//test_thread();
}
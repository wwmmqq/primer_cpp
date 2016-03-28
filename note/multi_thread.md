# c++11 5 个头文件
	#include <atomic>
	#include <thread>
	#include <mutex>
	#include <future>
	#include <condition_variable>

#mutex



# lock_guard unique_lock
	
	std::lock_guard: 与 Mutex RAII 相关 方便线程对互斥量上锁。
	std::unique_lock: 与 Mutex RAII 相关 方便线程对互斥量上锁，但提供了更好的上锁和解锁控制

	lock_guard 对象通常用于管理某个锁(Lock)对象，因此与 Mutex RAII 相关，方便线程对互斥量上锁，即在某个 lock_guard 对象的声明周期内，它所管理的锁对象会一直保持上锁状态；而 lock_guard 的生命周期结束之后，它所管理的锁对象会被解锁(注：类似 shared_ptr 等智能指针管理动态分配的内存资源 )。

	在 lock_guard 对象构造时，传入的 Mutex 对象(即它所管理的 Mutex 对象)会被当前线程锁住。在lock_guard 对象被析构时，它所管理的 Mutex 对象会自动解锁，由于不需要程序员手动调用 lock 和 unlock 对 Mutex 进行上锁和解锁操作，因此这也是最简单安全的上锁和解锁方式，尤其是在程序抛出异常后先前已被上锁的 Mutex 对象可以正确进行解锁操作，极大地简化了程序员编写与 Mutex 相关的异常处理代码。

	值得注意的是，lock_guard 对象并不负责管理 Mutex 对象的生命周期，lock_guard 对象只是简化了 Mutex 对象的上锁和解锁操作，方便线程对互斥量上锁，即在某个 lock_guard 对象的声明周期内，它所管理的锁对象会一直保持上锁状态；而 lock_guard 的生命周期结束之后，它所管理的锁对象会被解锁。




# <future>



# bind <functional>
	
	auto newCallable = bind(callable, arg_list)
	arg_list: 可包含形如 _n 的名字，这些“占位符”代表参数的位置
	void f(int n1, int n2, int n3, const int& n4, int n5);
	auto f1 = std::bind(f, _2, _1, 42, 11, 10);

	用于函数绑定的模板。接受一个可调用对象，生成一个新的可调用对象“适应”原对象的参数列表。

	The function template bind generates a forwarding call wrapper for f. Calling this wrapper is equivalent to invoking f with some of its arguments bound to args




# move forward

	std::move是无条件的转为右值引用，而std::forward是有条件的转为右值引用，更准确的说叫做Perfect forwarding（完美转发），而std::forward里面蕴含着的条件则是Reference Collapsing（引用折叠）。


# std::condition_variable

	std::condition_variable 是条件变量，std::condition_variable 对象通常使用 std::unique_lock<std::mutex> 来等待

	当 std::condition_variable 对象的某个 wait 函数被调用的时候，它使用 std::unique_lock(通过 std::mutex) 来锁住当前线程。当前线程会一直被阻塞，直到另外一个线程在相同的 std::condition_variable 对象上调用了 notification 函数来唤醒当前线程。wait() 函数也是自动调用 lck.lock()，使得 lck 的状态和 wait 函数被调用时相同。

	
















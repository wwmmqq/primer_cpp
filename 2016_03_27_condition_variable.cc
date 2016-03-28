#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

#include <chrono>

using std::cout;
using std::endl;
using std::cin;

std::mutex mtx; //全局互斥锁.
std::condition_variable cv; //全局条件变量.
std::atomic<bool> stop{false}; //全局标志位.

void do_print_id(int id)
{
    std::unique_lock <std::mutex> lck(mtx);
    while (!stop.load()) // 如果标志位为false, 则等待...
        cv.wait(lck); // 当前线程被阻塞, 当全局标志位变为 true 之后,线程被唤醒, 继续往下执行打印线程编号id.
    std::cout << "thread " << id << '\n';
}

void go()
{
    std::unique_lock <std::mutex> lck(mtx);
    stop.store(true); // 设置全局标志位为 true.
    cv.notify_all(); // 唤醒所有线程.
    //cv.notify_one();
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::thread threads[10];
    // spawn 10 threads:
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(do_print_id, i);

    std::cout << "10 threads ready to race...\n";
    std::cout << "10 threads ready to race...\n";

    go(); // go!

    for (auto &th : threads)
        th.join();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;
    std::cout << "Waited " << elapsed.count() << " ms\n";
    return 0;
}




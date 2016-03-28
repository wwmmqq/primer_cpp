#include <iostream>
#include <future>
#include <thread>
#include <string>
#include <stdio.h>

static std::string MakeFileName(const std::string& name, uint64_t number,
                                const char* suffix) {
  char buf[100];
  snprintf(buf, sizeof(buf), "/%06llu.%s",
           static_cast<unsigned long long>(number),
           suffix);
  return name + buf;
}

int main2()
{
    // future from a packaged_task
    std::packaged_task<int()> task([](){ return 7; }); // wrap the function
    std::future<int> f1 = task.get_future();  // get a future
    std::thread(std::move(task)).detach(); // launch on a thread
 
    // future from an async()
    std::future<int> f2 = std::async(std::launch::async, [](){ return 8; });
 
    // future from a promise
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread( [](std::promise<int> p){ p.set_value_at_thread_exit(9); }, 
        std::move(p) ).detach();
 
    std::cout << "Waiting..." << std::flush;
    //f1.wait();
    //f2.wait();
    //f3.wait();
    std::cout << "Done!\nResults are: "
              << f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';
}
int main()
{
    std::string a{"wmq"};
    char b[] = "hellow";
    std::cout << MakeFileName(a, 12, b) <<std::endl;
}
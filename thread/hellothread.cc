/***
	并行 vs 并发 vs 多核并发(并发的两种方式)vs 多cpu并行

	进行上下文的切换时，操作系统必须为当前运行的任务保存CPU的状态和指令指针，
	并计算出要切换到哪个任务，并为即将切换到的任务重新加载处理器状态。
	然后，CPU可能要将新任务的指令和数据的内存载入到缓存中，
	这会阻止CPU执行任何指令，从而造成的更多的延迟。



	有些处理器可以在一个核心上执行多个线程,但硬件并发在多处理器或多核系统上效果更加显著。
	硬件线程（hardware threads）最重要的因素是数量,也就是硬件上可以并发运行多少独立的任务。
	即便是具有真正硬件并发的系统，也很容易拥有比硬件“可并行最大任务数”还要多的任务需要执行，
	所以任务切换在这些情况下仍然适用。
***/

#include <iostream>
#include <thread>

void hello(int n)
{
	std::cout << "hello " << n <<std::endl;
}

class task
{
public:
	void operator ()()const{
		hello(555);
	}
	
};
int main()
{
	std::thread t1(hello, 5);
	task T;
	std::thread t2(T);
	std::thread t3((task()));
	std::thread t4([]{std::cout<<"888\n";});
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}

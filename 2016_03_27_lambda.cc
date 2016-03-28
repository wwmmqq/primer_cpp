#include <iostream>
#include <thread>
#include <atomic>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	auto f1 = [](int a, int b){return a + b;};
	cout<< f1(1,2)<<endl;
	cout << std::this_thread::get_id() <<endl;
}
#include <iostream>
#include <string>
#include <initializer_list>

#include <cstdarg>

using std::cout;
using std::cin; 
using std::endl;

void test1(std::initializer_list<std::string> ls)
{
	for (auto x : ls)
		cout << x <<endl;
}

void test2(int a...)
{
	int j = 0;
	va_list arg_ptr;
	va_start(arg_ptr,a);////将 arg_ptr 初始化为指向第一个参数

	cout << va_arg(arg_ptr,int) <<endl;
	cout << va_arg(arg_ptr,char*) <<endl;
	//cout << va_arg(arg_ptr,int) <<endl;
}



void test3(int a...)
{
	// va_list
	// va_arg()
	//va_start()
	int j = 0;
	va_list arg_ptr; //定义一个指向参数列表的变量
	va_start(arg_ptr, a); ////将 arg_ptr 初始化为指向第一个参数

	cout << a <<endl;

	while(j != -1) {//自定义的一个参数结束标志
		j = va_arg(arg_ptr,int); //获取下一个参数
		cout << j << endl;
	}
	va_end(arg_ptr); //结束
}


int main(int argc, char const *argv[])
{
	std::initializer_list<std::string> ls{"a", "b"};
	test1({"ab", "db", "123"});

	test2(1,2,"goodjob", -1);
	test3(98,99,-1);

	return 0;
}
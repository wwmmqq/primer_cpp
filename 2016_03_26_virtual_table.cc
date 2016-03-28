//http://blog.csdn.net/haoel/article/details/1948051/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Base {
public:
	static void f(void) { cout << "Base::f" << endl; }
	void g(void) { cout << "Base::g" << endl; }
	virtual void h(void) { cout << "Base::h" << endl; }
	virtual void k(void) { cout << "Base::k" << endl; }
};

typedef void(*Fun)(void);

int main()
{
	Base b;

	Fun pFun = NULL;

	cout << "虚函数表地址：" << (int*)&b << endl;
	cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;

	
	pFun = &Base::f;
	pFun();
	// &Base::f() error!!!

	//auto *kk = &Base::g;
	//kk();

	cout << &Base::g << endl;
	cout << &Base::h << endl;
	cout << &Base::k << endl;
	

	// Invoke the first virtual function 
	//pFun = (Fun)*((int*)*(int*)(&b));
	//pFun();
}


# 基本概念
	1、多态性 
	指相同对象收到不同消息或不同对象收到相同消息时产生不同的实现动作。C++支持两种多态性：编译时多态性，运行时多态性。 
  		a、编译时多态性：通过重载函数实现 
  		b、运行时多态性：通过虚函数实现。 
  	2、虚函数 
  		虚函数是在基类中被声明为virtual，并在派生类中重新定义的成员函数，可实现成员函数的动态覆盖（Override）
  	3、抽象类 
  		包含纯虚函数的类称为抽象类。由于抽象类包含了没有定义的纯虚函数，所以不能定义抽象类的对象。


# 多态(polymorphism)

多态性可以简单地概括为“一个接口，多种方法”，程序在运行时才决定调用的函数，它是面向对象编程领域的核心概念。

C++多态性是通过虚函数来实现的，虚函数允许子类重新定义成员函数，而子类重新定义父类的做法称为覆盖(override)或者称为重写。

重写： 有两种，直接重写成员函数和重写虚函数，只有重写了虚函数的才能算作是体现了C++多态性。

重载： 允许有多个同名的函数，而这些函数的参数列表不同，允许参数个数不同，参数类型不同，或者两者都不同。

多态 vs 非多态
	实质区别就是函数地址是早绑定还是晚绑定。如果函数的调用，在编译器编译期间就可以确定函数的调用地址，并生产代码，是静态的，就是说地址是早绑定的。而如果函数调用的地址不能在编译器期间确定，需要在运行时才确定，这就属于晚绑定。

多态作用：
	封装可以使得代码模块化，继承可以扩展已存在的代码，他们的目的都是为了代码重用。而多态的目的则是为了接口重用。也就是说，不论传递过来的究竟是那个类的对象，函数都能够通过同一个接口调用到适应各自对象的实现方法。

实现：
	最常见的用法就是声明基类的指针，利用该指针指向任意一个子类对象，调用相应的虚函数，可以根据指向的子类的不同而实现不同的方法。如果没有使用虚函数的话，即没有利用C++多态性，则利用基类指针调用相应的函数的时候，将总被限制在基类函数本身，而无法调用到子类中被重写过的函数。因为没有多态性，函数调用的地址将是一定的，而固定的地址将始终调用到同一个函数，这就无法实现一个接口，多种方法的目的了。

令人迷惑的隐藏规则
本来仅仅区别重载与覆盖并不算困难，但是C++的隐藏规则使问题复杂性陡然增加。
这里“隐藏”是指派生类的函数屏蔽了与其同名的基类函数，规则如下：
	（1）如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual关键字，基类的函数将被隐藏（注意别与重载混淆。
	（2）如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。此时，基类的函数被隐藏（注意别与盖混淆）。


# 列子
	//小结：1、有virtual才可能发生多态现象
	// 2、不发生多态（无virtual）调用就按原类型调用
	#include<iostream>
	using namespace std;

	class Base
	{
	public:
		virtual void f(float x)
		{
			cout<<"Base::f(float)"<< x <<endl;
		}
		void g(float x)
		{
			cout<<"Base::g(float)"<< x <<endl;
		}
		void h(float x)
		{
			cout<<"Base::h(float)"<< x <<endl;
		}
	};
	class Derived : public Base
	{
	public:
		virtual void f(float x)
		{
			cout<<"Derived::f(float)"<< x <<endl;   //多态、覆盖
		}
		void g(int x)
		{
			cout<<"Derived::g(int)"<< x <<endl;     //隐藏
		}
		void h(float x)
		{
			cout<<"Derived::h(float)"<< x <<endl;   //隐藏
		}
	};
	int main(void)
	{
		Derived d;
		Base *pb = &d;
		Derived *pd = &d;
		// Good : behavior depends solely on type of the object
		pb->f(3.14f);   // Derived::f(float) 3.14
		pd->f(3.14f);   // Derived::f(float) 3.14

		// Bad : behavior depends on type of the pointer
		pb->g(3.14f);   // Base::g(float)  3.14
		pd->g(3.14f);   // Derived::g(int) 3 

		// Bad : behavior depends on type of the pointer
		pb->h(3.14f);   // Base::h(float) 3.14
		pd->h(3.14f);   // Derived::h(float) 3.14
		return 0;
	}

	函数Derived::f(float)覆盖了Base::f(float)。
	函数Derived::g(int)隐藏了Base::g(float)，而不是重载。
	函数Derived::h(float)隐藏了Base::h(float)，而不是覆盖。



# C++纯虚函数
	纯虚函数是在基类中声明的虚函数，它在基类中没有定义，但要求任何派生类都要定义自己的实现方法。在基类中实现纯虚函数的方法是在函数原型后加“=0”
	eg: virtual void funtion()=0 

	引入原因：
		1、为了方便使用多态特性，我们常常需要在基类中定义虚拟函数。 
		2、在很多情况下，基类本身生成对象是不合情理的。

# reference
	1. http://blog.csdn.net/hackbuteer1/article/details/7475622

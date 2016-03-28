#include <iostream>

namespace my_cpp {
class Base {
public:
	virtual void f(int x){
		std::cout <<" Base f: "<< x << std::endl;
	}

	void g(int x){
		std::cout <<" Base g: "<< x << std::endl;
	}

	void h(int x){
		std::cout <<" Base h: "<< x << std::endl;
	}
};

class Derived : public Base{
public:
	void f(int x){ //多态、覆盖  
		std::cout <<" Derived f: "<< x << std::endl;
	}

	void g(int x){ //隐藏  
		std::cout <<" Derived g: "<< x << std::endl;
	}

	void h(int x){ //隐藏  
		std::cout <<" Derived h: "<< x << std::endl;
	}
};

}// namespace my_cpp

int main()
{
	my_cpp::Base b;
	my_cpp::Derived d;

	my_cpp::Derived *p_d = &d;
	my_cpp::Base *p_b = &d;

	p_d->f(1);
	p_d->g(1);
	p_d->h(1);

	p_b->f(1);
	p_b->g(1);
	p_b->h(1);

	//p_d = &b; error no viable conversion from 'my_cpp::Base *' to 'my_cpp::Derived'



	//// test 2

	my_cpp::Derived *ptr = (my_cpp::Derived *)&b;
	ptr->f(2);
	ptr->g(2);
}




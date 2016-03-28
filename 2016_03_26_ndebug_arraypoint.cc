#include <iostream>
#include <cassert>
#include <typeinfo>
using std::cout;
using std::cin;
using std::endl;

void point()
{
	typedef int arrT1[2];
	using arrT2 = int[2];

	int arr[2];
	//arrT1 gg;
	//gg[0] = 11;
	//cout << gg[0] <<endl;
	int arr2[2][2];

	cout << arr << endl;
	cout << &arr << endl;

	int *p1 = arr;
	int (*p2)[2] = &arr;

	cout << *p2 <<" type: " << typeid(p2).name()<<endl;

	**p2 = 99;
	*(*p2+1) = 100;

	cout << **p2 << " " <<*(*p2+1) <<endl;


	cout <<"arr2:  " <<arr2 << " type: " << typeid(arr2).name()<< endl;
	cout << "&arr2:  " <<&arr2 <<" type: " << typeid(&arr2).name()<< endl;
	cout << "arr2[0]:  " <<arr2[0] <<" type: " << typeid(arr2[0]).name()<< endl;
	cout << "&arr2[0]:  " <<&arr2[0] <<" type: " << typeid(&arr2[0]).name()<< endl;
	p2 = &arr2[0];
}

int main()
{
	point();
	//g++ -D NDEBUG 2016_03_26_ndebug.cc -> #define NDEGUG
	#ifdef NDEBUG
		cout << "__FILE__: " << __FILE__ <<endl;
		cout << "__LINE__: " << __LINE__ <<endl;
		cout << "__TIME__: " << __TIME__ <<endl;
		cout << "__DATE__: " << __DATE__ <<endl;
	#endif
	assert(1);// 1. if DEBUG is used , aasert do nothing. 2. if expr is true do noting.
}
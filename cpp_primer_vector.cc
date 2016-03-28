#include <iostream>
#include <cctype>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void use_vector()
{
	string s1("hello");
	string s2(10, 'g');
	string s3(s1);
	cout << s2 <<endl;

	string::iterator it = s1.begin();
	cout<< *it <<endl;
	*it = 'H';
	it = s1.end();
	cout << *(it - 1)<<endl;

	string::const_iterator it2 = s1.cbegin();
	cout<< *it2 <<endl;

	string::const_iterator it3 = s1.begin();
	cout<< *it3 <<endl;

	int n = 0;
	string word;
	vector<string> text;
	
	const string s4("keep g9ing!");
	for (auto &c :s4){
		if (isdigit(c))
			cout << c;
	}
	cout <<endl;
}

void use_array_point()
{
	int a[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};

	int *p1 = &a[0][0];
	cout << *p1 <<endl;

	int b[5] = {99,1,2,3,4};
	int *p2 = b;
	cout << *p2 << endl;

	int (*p3)[4] = &a[2];
	cout << **p3 <<endl;

	cout <<"a[2]: "<< *(*(&a[2]) + 1)<< endl;
	cout << **(&a[2]) << endl;
	cout << &a[2] << endl;
	cout << a[2] << endl;

	int *p4[4];
	int n = 9;
	p4[0] = &n;
	for (auto val : *p3)
		cout << val <<endl;
}

void use_string()
{
	const string s1("good job");
	const string s2("abcd");
	//s1[0] = 'G'; //error: read-only variable is not assignable

	//s1 = s2;	//error: no viable overloaded '='
	cout<< s1<<endl;

	char s3[] = "efg";
	char s4[] = "123";
	const char * const p =  s3;
	cout << *(p + 1) <<endl;
	//p = s4;
	//*p = 'A';
	cout << *p << endl;
}

void test_throw()
{
	int i = 9;
	if (i < 10)
		throw std::invalid_argument("wmq999");
}


int main()
{	
	//cout<<__cplusplus<<endl;
	//use_string();
	try {
		test_throw();
	} catch(std::invalid_argument e){
		cout << e.what() << endl;
	}
}	
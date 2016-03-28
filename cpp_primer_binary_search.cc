#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int binary_search_1(const vector<int>& v, int sought)
{
	auto beg = v.begin(), end = v.end();
	auto mid = v.begin() + (end - beg)/2;

	while(mid != end and *mid != sought) {
		if (sought < *mid)
			end = mid;
		else
			beg = mid + 1;
		mid = beg + (end - beg)/2;
	}

	//cout << "error: "<< *mid << endl;
	// there is some bug about mid to v.end()
	/*if (*mid == sought)
		return 1;
	else
		return -1;
	*/
	if (mid != v.end())
	{
		if (*mid == sought)
			return 1;
		else 
			return -1;
	}
	else
		return -1;
}


// return the index of v or -1
int binary_search_2(const vector<int>& v, int sought)
{
	decltype(v.size()) beg = 0, end = v.size()-1;// there end must is len - 1
	decltype(v.size()) mid = beg + (end - beg)/2;
	while (mid != end and v[mid] != sought) {
		if (sought < v[mid])
			end = mid;
		else
			beg = mid + 1;
		mid = beg + (end - beg)/2;
	}

	if (v[mid] == sought)
		return mid;
	else
		return -1;
}


// best way to reach the binary search
int binary_search_3(const vector<int>& v, int sought)
{
	int beg = 0, end = v.size()-1;
	int mid;

	while(beg <= end) {
		mid = beg + (end - beg)/2;
		if (v[mid] == sought)
			return mid;

		if (sought < v[mid])
			end = mid - 1;
		else
			beg = mid + 1;
	}
	return -1;
}


int main()
{
	vector<int> v{1,2,3,4,5,6,7,8,9};
	cout << binary_search_3(v, 11)<<endl;
	cout << binary_search_3(v, 9)<<endl;
	cout << binary_search_3(v, 1)<<endl;
	cout << binary_search_3(v, 4)<<endl;
}


#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

//algorithm中remove_if算法的实现
namespace STLAlgorithm
{
	template<class Iterator, class Predicate>
	Iterator remove_if(Iterator beg, Iterator end, Predicate op)
	{
		beg = find_if(beg, end, op);
		if (beg == end)
		{
			return beg;
		}
		else
		{
			Iterator next = beg;
			return remove_copy_if(++next, end, beg, op);
		}
	}
}

//自定义remove_if算法
namespace myAlgorithm
{
	template<class Iterator, class Predicate>
	Iterator remove_if(Iterator start, Iterator finish, Predicate op)
	{
		while (start != finish && !op(*start))
		{
			++start;
		}
		if (start == finish)
		{
			return start;
		}
		else
		{
			Iterator next = start;
			return remove_copy_if(++next, finish, start, op);
		}
	}
}

namespace myAlgorithm_2
{
	template<class Iterator, class Predicate>
	Iterator remove_if(Iterator beg, Iterator end, Predicate op)
	{
		beg = find_if(beg, end, op);
		if (beg == end)
		{
			return beg;
		}
		else
		{
			Iterator next = beg;
			return copy(++next, end, beg);
		}
	}
}

//判断式仿函数
class NTH
{
private:
	int nth;
	int count;

public:
	NTH(int n) :nth(n), count(0){};
	bool const operator()(int)
	{
		return ++count == nth;
	}
};

int main()
{
	cout << "fds" << endl;
	list<int> coll(9);
	int num[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	copy(num, num + sizeof(num) / sizeof(num[0]), coll.begin());
	cout << "coll: ";
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	list<int>::iterator pos;
	//pos = myAlgorithm::remove_if(coll.begin(), coll.end(), NTH(3));//Right,delete only one element
	//pos =STLAlgorithm::remove_if(coll.begin(), coll.end(), NTH(3));//Error,delete two element
	//pos = myAlgorithm_2remove_if(coll.begin(), coll.end(), NTH(3));//Right,delete only one element

	cout << "coll: ";
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	coll.erase(pos, coll.end());
	cout << "coll: ";
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}

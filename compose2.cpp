//两个"运算准则"测试
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include "D:\\C++STL\\一元组合函数配接器\\compose21.hpp"
#include "D:\\C++STL\\print.hpp"

using namespace std;

int main()
{
	vector<int> coll;
	for (int i = 1; i <= 9; ++i)
	{
		coll.push_back(i);
	}
	myNamespace::print_elements(coll);

	//function called for remove all elements that are greater four and less than seven
	vector<int>::iterator pos;
	pos = remove_if(coll.begin(), coll.end(), compose_f_gx_hx(logical_and<bool>(), bind2nd(greater<int>(), 4), bind2nd(less<int>(), 7)));
	coll.erase(pos, coll.end());
	myNamespace::print_elements(coll);
	return 0;
}

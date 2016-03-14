//一个运行准则测试
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include "D:\\C++STL\\一元组合函数配接器\\compose11.hpp"
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

	//for each element add 10 and multiply by 5

	transform(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "), compose_f_gx(bind2nd(multiplies<int>(), 5), bind2nd(plus<int>(), 10)));
	cout << endl;
	//传给compose_f_gx的第二个运算会先执行，所以compose_f_gx(bind2nd(multipiies<int>(),5),bind2nd(plus<int>(),10))会产生一个一元仿函数
	//结果:
		//1 2 3 4 5 6 7 8 9
		//55 60 65 70 75 80 85 90 95
	return 0;
}

#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

//判断式仿函数
class NTH
{
private:
	int nth;
	int count;

public:
	NTH(int n) :nth(n), count(0){};
	bool operator()(int)
	{
		return ++count == nth;
	}
};

int main()
{
	list<int> coll(9);
	int num[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	copy(num, num + sizeof(num) / sizeof(num[0]), coll.begin());
	cout << "coll: ";
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	list<int>::iterator pos;
	pos = remove_if(coll.begin(), coll.end(), NTH(3));//将NTH返回为真的元素删掉，实则容器后面元素向前复制，但是不改变容器大小
	
	cout << "coll: ";
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	coll.erase(pos, coll.end());//真正意义上的删除满足NTH返回为真的元素
	cout << "coll: ";
	//结果是:1,2,4,5,7,8,9，解决方法见PredecateAndFunctors.cpp
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}

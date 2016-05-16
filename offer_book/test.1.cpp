/*************************************************************************
    > File Name: test.1.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May 16 13:15:33 2016
 ************************************************************************/
#include <iostream>

class A
{
private:
	int value;

public:
	A(int n)
	{
		value = n;
	}

	//A(A other) 会编译错误，因为标准要求复制构造函数必须是引用类型
	A(A& other)
	{
		value = other.value;
	}

	void print()
	{
		std::cout << value << std::endl;
	}
};

int main()
{
	A a(10);  //not A a = 10;
	A b = a;
	b.print();
	return 0;
}

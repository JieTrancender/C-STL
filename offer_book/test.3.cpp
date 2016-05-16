/*************************************************************************
    > File Name: test.3.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May 16 14:39:27 2016
 ************************************************************************/
#include <iostream>

//当数组的作为参数进行传递使，自动弱化成指针，因此对指针求sizeof 32位机器为4,64位机器为8
int get_size(int data[])
{
	return sizeof(data);
}

int main(int argc, char** argv)
{
	int data1[] = {
		1, 2, 3, 4, 5
	};

	int size1 = sizeof(data1);

	int *data2 = data1;
	int size2 = sizeof(data2);

	int size3 = get_size(data1);

	std::cout << size1 << ", " << size2 << ", " << size3 << std::endl;
}

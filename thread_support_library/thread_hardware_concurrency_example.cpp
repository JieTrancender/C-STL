/*************************************************************************
    > File Name: thread_hardware_concurrency_example.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Mar 15 17:04:33 2016
 ************************************************************************/

//std::thread::hardware_concurrency
//static unsigned hardware_concurrency();返回收益支持的并发数量

#include <iostream>
#include <thread>

int main(int argc, char** argv)
{
	unsigned int n = std::thread::hardware_concurrency();
	std::cout << n << " concurrent threads are supported." << std::endl;
	return 0;
}

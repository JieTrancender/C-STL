/*************************************************************************
    > File Name: thread_thread_example.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Mar 15 15:41:25 2016
 ************************************************************************/

#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

void func1(int n)
{
	for(int i = 0; i < 5; ++i)
	{
		std::cout << "Thread 1 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void func2(int& n)
{
	for(int i = 0; i < 5; ++i)
	{
		std::cout << "Thread 2 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

int main(int argc, char** argv)
{
	int n = 0;
	std::thread t1;
	std::thread t2(func1, n + 1);
	std::thread t3(func2, std::ref(n));
	std::thread t4(std::move(t3));
	t2.join();
	t4.join();
	std::cout << "Final value of n is " << n << std::endl;

	return 0;
}

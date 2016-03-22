/*************************************************************************
    > File Name: thread_yield_example.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Wed Mar 23 06:42:16 2016
 ************************************************************************/
#include <iostream>
#include <chrono>
#include <thread>

void little_sleep(std::chrono::microseconds us)
{
	auto start = std::chrono::high_resolution_clock::now();
	auto end = start + us;
	do
	{
		std::this_thread::yield();
	}while(std::chrono::high_resolution_clock::now() < end);
}

int main(int argc, char** argv)
{
	auto start = std::chrono::high_resolution_clock::now();

	little_sleep(std::chrono::microseconds(100));

	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	std::cout << "waited for " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " microseconds\n";
	return 0;
} 

/*************************************************************************
    > File Name: thread_joinable_example.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Mar 15 16:29:13 2016
 ************************************************************************/

#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main(int argc, char** argv)
{
	std::thread t;
	std::cout << "Before starting,joinable: " << t.joinable() << std::endl;

	t = std::thread(foo);
	std::cout << "After starting,joinable: " << t.joinable() << std::endl;

	t.join();
	std::cout << "After joining,joinable: " << t.joinable() << std::endl;
	return 0;
}

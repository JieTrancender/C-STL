/*************************************************************************
    > File Name: thread_detach_example.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Mar 15 17:43:00 2016
 ************************************************************************/

//std::thread::detach
//void detach();分离执行的线程和线程标识符,允许线程无依靠的继续执行,任何申请的资源将释放一旦线程结束

#include <iostream>
#include <chrono>
#include <thread>

void independent_thread()
{
	std::cout << "Starting concurrent thread.\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Exiting concurrent thread.\n";
}

void thread_caller()
{
	std::cout << "Starting thread caller.\n";
	std::thread t(independent_thread);
	t.detach();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Exiting thread caller.\n";
}

int main(int argc, char** argv)
{
	thread_caller();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}

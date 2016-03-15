/*************************************************************************
    > File Name: thread_join_example.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Mar 15 17:25:52 2016
 ************************************************************************/

//std::thread::join
//void join();锁定当前线程直到标识符线程执行完成

#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void bar()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main(int argc, char** argv)
{
	std::cout << "starting first helper..." << std::endl;
	std::thread helper1(foo);

	std::cout << "starting second helper..." << std::endl;
	std::thread helper2(bar);

	std::cout << "waiting for helpers to finish..." << std::endl;
	helper1.join();
	helper2.join();
	std::cout << "done!" << std::endl;
	return 0;
}

/*************************************************************************
    > File Name: thread_get_id_example.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Mar 15 16:35:14 2016
 ************************************************************************/

//std::thread::id get_id() const;

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex g_mutex;

void foo()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void func()
{
	std::thread::id this_id = std::this_thread::get_id();
	g_mutex.lock();
	std::cout << "Thread: " << this_id << "executing...\n";
	g_mutex.unlock();

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main(int argc, char** argv)
{
	std::thread t1(foo);
	std::thread::id t1_id = t1.get_id();

	std::thread t2(foo);
	std::thread::id t2_id = t2.get_id();

	std::cout << "t1's id: " << t1_id << std::endl;
	std::cout << "t2's id: " << t2_id << std::endl;
	std::cout << "main's id: " << std::this_thread::get_id() << std::endl;
	
	std::thread t3(func);
	std::thread t4(func);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}

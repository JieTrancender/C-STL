/*************************************************************************
    > File Name: thread_native_handle_example.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Mar 15 16:53:01 2016
 ************************************************************************/

//std::thread::native_handle返回实现定义的底层线程处理
//native_handle_type native_handle();

#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <cstring>
#include <pthread.h>

std::mutex io_mutex;

void func(int num)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));

	sched_param sch;
	int policy;
	pthread_getschedparam(pthread_self(), &policy, &sch);
	std::lock_guard<std::mutex> lk(io_mutex);
	std::cout << "Thread " << num << " is executing at priority " << sch.sched_priority << std::endl;
}

int main(int argc, char** argv)
{
	std::thread t1(func, 1), t2(func, 2);
	
	sched_param sch;
	int policy;
	pthread_getschedparam(t1.native_handle(), &policy, &sch);
	sch.sched_priority = 20;
	if(pthread_setschedparam(t1.native_handle(), SCHED_FIFO,&sch))
	{
		std::cout << "Failed to setschedparam: " << std::strerror(errno) << std::endl;
	}

	t1.join();
	t2.join();
	return 0;
}

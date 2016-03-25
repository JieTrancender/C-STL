/*************************************************************************
    > File Name: test.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Fri Mar 25 13:42:07 2016
 ************************************************************************/
#include "thread_safe_stack.hpp"
#include <iostream>
#include <string>
#include <memory>

int main(int argc, char** argv)
{
	ThreadSafeStack<std::string> stack;

	stack.push("Windows");
	stack.push("Linux");
	stack.push("Android");
	stack.push("Ios");

	try
	{
		std::shared_ptr<std::string> ptr = stack.pop();
		std::cout << *ptr << std::endl;

		ptr = stack.pop();
		std::cout << *ptr << std::endl;

		std::string str;
		stack.pop(str);
		std::cout << str << std::endl;

		stack.pop(str);
		std::cout << str << std::endl;

		stack.pop(str);
		std::cout << str << std::endl;
	}
	catch(const char* str)
	{
		std::cerr << *str << std::endl;
	}
	return 0;
}

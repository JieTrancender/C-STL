/*************************************************************************
    > File Name: thread_safe_swap.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Fri Mar 25 16:57:55 2016
 ************************************************************************/
#include <stack>
#include <iostream>
#include <mutex>
#include <algorithm>
#include <string>

template <typename T>
void swap(std::stack<T>& lhs, std::stack<T>& rhs);

template <typename T>
class Test
{
private:
	std::stack<T> m_data_stack;
	std::mutex m_mutex;
public:
	Test<T>(std::stack<T> const& stack): m_data_stack(stack){}

	Test<T>(T object)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		m_data_stack.push(object);
	}

	T get_value() const
	{
		return m_data_stack.top();
	}

	friend void swap(std::stack<T>& lhs, std::stack<T>& rhs)
	{
		if(&lhs == &rhs)
			return;
		std::lock(lhs.m_mutex, rhs.m_mutex);
		std::lock_guard<std::mutex> lock_lhs(lhs.m_mutex, std::adopt_lock);
		std::lock_guard<std::mutex> lock_rhs(rhs.m_mutex, std::adopt_lock);
		swap(lhs.m_data_stack, rhs.m_data_stack);
	}
};

template <typename T>
void swap(std::stack<T>& lhs, std::stack<T>& rhs)
{
	std::swap(lhs, rhs);
}

int main(int argc, char** argv)
{
	Test<std::string> test_a(std::string("Windows"));
	Test<std::string> test_b(std::string("Linux"));
	
	std::cout << "test_a's top value = " << test_a.get_value() << std::endl;
	std::cout << "test_b's top value = " << test_b.get_value() << std::endl;

	swap(test_a, test_b);
	std::cout << "test_a's top value = " << test_a.get_value() << std::endl;
	std::cout << "test_b's top value = " << test_b.get_value() << std::endl;
	
	return 0;
}

#ifndef THREAD_SAFE_STACK

#include <memory>
#include <mutex>
#include <stack>
#include <exception>
#include <cstring>

struct empty_stack: std::exception
{
	const char* what() const throw()
	{
		char* str = new char[18];
		strcpy(str, "Empty stack");
		return str;
	}
};

template <typename anytype>
class ThreadSafeStack
{
private:
	std::stack<anytype> m_data;
	mutable std::mutex m_mutex;
public:
	ThreadSafeStack() {}

	ThreadSafeStack(const ThreadSafeStack& other)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		m_data = other.m_data;
	}

	ThreadSafeStack& operator=(const ThreadSafeStack&) = delete;

	void push(anytype value)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		m_data.push(value);
	}

	std::shared_ptr<anytype> pop()
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if(m_data.empty())
			throw empty_stack();
		std::shared_ptr<anytype> res(std::make_shared<anytype>(m_data.top()));
		m_data.pop();
		return res;
	}

	void pop(anytype &value)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if(m_data.empty())
			throw empty_stack();
		value = m_data.top();
		m_data.pop();
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		return m_data.empty();
	}
};

#endif	//THREAD_SAFE_STACK

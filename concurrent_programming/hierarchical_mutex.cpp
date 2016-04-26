/*************************************************************************
    > File Name: hierarchical_mutex.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Fri Mar 25 17:45:53 2016
 ************************************************************************/
#include <mutex>

class HierarchicalMutex
{
	std::mutex m_internal_mutex;
	unsigned long const hierarchy_value;
	unsigned long previous_hierarchy_value;
	static thread_local unsigned long this_thread_hierarchy_value;

	void check_for_hierarchy_violation()
	{
		if (this_thread_hierarchy_value <= hierarchy_value)
			throw std::logic_error("mutex hierarchy violated");
	}

	void update_hierarchy_value()
	{
		previous_hierarchy_value = this_thread_hierarchy_value;
		this_thread_hierarchy_value = hierarchy_value;
	}
public:
	explict HierarchicalMutex(unsigned long value): hierarchy_value(value), previous_hierarchy_value(0){}

	void lock()
	{
		check_for_hierarchy_violation();
		internal_mutex.lock();
		update_hierarchy_value();
	}

}

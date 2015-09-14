#include <iostream>

namespace myNamespace
{
	template <typename anytype>
	inline void print_elements(const anytype &coll)
	{
		for (auto i : coll)
			cout << i << ' ';
		cout << endl;
	}
}

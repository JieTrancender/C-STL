/*************************************************************************
    > File Name: array_example.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Mar 15 00:29:09 2016
 ************************************************************************/

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

int main(int argc, char** argv)
{
//	std::array<int, 3>a1{ {1, 2, 3} };//不能使用
	std::array<int, 3>a2{1, 2, 3};
	std::array<std::string, 2>a3{std::string("a"), "b"};

//	std::sort(a1.begin(), a2.end());
	std::reverse_copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	for(const auto& s: a3)
		std::cout << s << ' ';
	std::cout << std::endl;
	std::cout << "Hello, World!" << std::endl;
	return 0;
}

/*************************************************************************
    > File Name: file_test.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May 16 23:15:51 2016
 ************************************************************************/
#include <iostream>
#include <fstream>

int main()
{
	std::fstream file;
	file.open("file_test.txt", std::ios::in | std::ios::out | std::ios::binary | std::ios:: ate);
	if (file.is_open())
	{
		file << "This is the first line." << std::endl;
		file << "This is the second line." << std::endl;
		file.close();
	}
}

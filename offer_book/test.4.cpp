/*************************************************************************
    > File Name: test.4.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May 16 14:47:53 2016
 ************************************************************************/
#include <iostream>

bool find(int* matrix, int rows, int columns, int number)
{
	bool found = false;

	if (matrix != NULL && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		
		while (row < rows && column >= 0)
		{
			if (matrix[row * columns + column] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row * columns + column] > number)
				--column;
			else
				++row;
		}
	}
	return found;
}

int main(int argc, char** argv)
{
	int matrix[] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
	int *test;

	std::cout << find(matrix, 4, 4, 7) << std::endl;
	std::cout << find(matrix, 4, 4, 0) << std::endl;
	std::cout << find(test, 4, 4, 4) << std::endl;
}

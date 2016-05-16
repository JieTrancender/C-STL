/*************************************************************************
    > File Name: test.5.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May 16 15:15:36 2016
 ************************************************************************/
/*
 *题目要求:替换字符串中的空格字符为"%20"
 *
 *测试用例:空指针，替换后会超过原大小，没有空格，空格位于最前面、最后面，又连续多个空格，字符串全部都是空格
 *
 * */
#include <iostream>

void replace_blank(char *string, int length)
{
	if (string == nullptr || length < 0)
		return;

	int original_length = 0;
	int number_of_blank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		++original_length;
		if (string[i] == ' ')
			++number_of_blank;
		++i;
	}

	int new_length = original_length + number_of_blank * 2;
	if (new_length > length)
		return;

	int index_of_original = original_length;
	int index_of_new = new_length;

	while (index_of_original >= 0 && index_of_new > index_of_original)  //判断index_of_original小于index_of_new是一种优化
	{
		if (string[index_of_original] == ' ')
		{
			string[index_of_new--] = '0';
			string[index_of_new--] = '2';
			string[index_of_new--] = '%';
		}
		else
			string[index_of_new--] = string[index_of_original];
		--index_of_original;
	}
}

int main(int argc, char** argv)
{
	char str1[35] = "i am a student.";
	char str2[35] = "  i am a student.";
	char str3[35] = "  i am a student. ";
	char str4[35] = "    ";
	char str5[35];

	replace_blank(str1, sizeof(str1));
	replace_blank(str2, sizeof(str2));
	replace_blank(str3, sizeof(str3));
	replace_blank(str4, sizeof(str4));
	replace_blank(str5, sizeof(str5));

	std::cout << str1 << ' ' << str2 << ' ' << str3 << " " << str4 << ' ' << str5 << std::endl;


	return 0;
}

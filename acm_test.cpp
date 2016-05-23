/*************************************************************************
    > File Name: acm_test.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: 2016年05月21日 星期六 19时27分00秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <string>

using namespace std;

void B()
{
	map<string, int> _map;
	string str;
	freopen("test.txt", "r", stdin);
	freopen("test_out.txt", "w", stdout);
	while (getline(cin, str))
	{
		if (str.size() == 0)
			break;
		int len = str.size();
		for (int i = len; i > 0; --i)
		{
			_map[str]++;
			str.resize(--len);
		}
	}

	while (cin >> str)
	{
		cout << str << ' ' << _map[str] << endl;
	}
	fclose(stdin);
	fclose(stdout);
}

void test()
{
	string str = "i am a student.";
	string::size_type index = str.find("student");
	if (index == string::npos)
	{
		cout << "Can't find";
	}

	else
	{
		cout << str.substr(index) << endl;
	}
}

int main()
{
	B();
}

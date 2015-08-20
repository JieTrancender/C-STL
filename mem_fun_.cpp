//函数配接器mem_fun_ref 和 mem_fun 被调用的成员函数必须是const
//mem_fun_ref对应类对象
//mem_fun对应类对象指针

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <string>

using namespace std;

class Person
{
private:
	string m_name;

public:

	Person(string &str) :m_name(str){};
	void print() const
	{
		cout << m_name << endl;
	}
	void printWithPrefix(string prefix) const
	{
		cout << prefix << m_name << endl;
	}
};

void foo(const vector<Person> &coll)
{
	for_each(coll.begin(), coll.end(), mem_fun_ref(&Person::print));
	for_each(coll.begin(), coll.end(), bind2nd(mem_fun_ref(&Person::printWithPrefix), "Person: "));
}

void ptrfoo(const vector<Person*>& coll)
{
	for_each(coll.begin(), coll.end(), mem_fun(&Person::print));
	for_each(coll.begin(), coll.end(), bind2nd(mem_fun(&Person::printWithPrefix), "Person: "));
}

int main()
{
	Person stu_1(string("莫杰"));
	Person stu_2(string("霍志强"));
	Person stu_3(string("孟庆飞"));
	vector<Person> coll;
	coll.push_back(stu_3);
	coll.push_back(stu_2);
	coll.push_back(stu_1);
	foo(coll);
	vector<Person*> col;
	Person *stu_4 = new Person{ string("冰杰") };
	Person *stu_5 = new Person{ string("妹妹") };
	Person *stu_6 = new Person{ string("爱明") };
	col.push_back(stu_4);
	col.push_back(stu_5);
	col.push_back(stu_6);
	ptrfoo(col);
	return 0;
}

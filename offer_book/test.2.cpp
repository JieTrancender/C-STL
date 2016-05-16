/*************************************************************************
    > File Name: test.2.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May 16 13:33:57 2016
 ************************************************************************/
/*
 *题目:要求添加一个赋值运算符
 *解决思路:
 *  范围值类型为该类型的引用
 *  传入的参数为常量引用
 *  释放自身已有内存
 *  判断是否和this是同一个实例
 *
 * */
#include <iostream>

class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString();

private:
	char* m_pData;
};

CMyString& operator=(const CMyString& str)
{
	if (this != &str)
	{
		CMyString strTemp(str);
		char *pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}

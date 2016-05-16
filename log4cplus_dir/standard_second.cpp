/*************************************************************************
    > File Name: standard_second.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May  9 22:03:56 2016
 ************************************************************************/
#include <iostream>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/layout.h>
#include <log4cplus/fileappender.h>

using namespace log4cplus;
using namespace log4cplus::helpers;

const int loop_count = 200000;

int main(int argc, char** argv)
{
	SharedAppenderPtr _append(new RollingFileAppender("test.log", 5*1024, 5));
	_append->setName("file test");

	std::auto_ptr<Layout> _layout(new TTCCLayout());
	_append->setLayout(_layout);
	Logger::getRoot().addAppender(_append);

	Logger root = Logger::getRoot();
	Logger test = Logger::getInstance("test");
	Logger subTest = Logger::getInstance("test.subtest");

	for (int i = 0; i < loop_count; ++i)
	{
//		NDCContextCreator _context("loop");
		LOG4CPLUS_DEBUG(subTest, "Entering loop #" << i);
	}

	return 0;
}

/*************************************************************************
    > File Name: log4cplus_test.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Apr 26 10:01:37 2016
 ************************************************************************/
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>

int main()
{
	log4cplus::BasicConfigurator config;
	config.configure();
	log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("main"));
	LOG4CPLUS_WARN(logger, LOG4CPLUS_TEXT("Hello, World!"));
	return 0;
}

/*************************************************************************
    > File Name: demo_of_second.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Apr 26 22:07:18 2016
 ************************************************************************/

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <iomanip>

using namespace log4cplus;

int main(int argc, char** argv)
{
	BasicConfigurator config;
	config.configure();

	Logger logger = Logger::getInstance("main");
	LOG4CPLUS_WARN(logger, "Hello, World!");
	return 0;
}

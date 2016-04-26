/*************************************************************************
    > File Name: demo_of_third.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Apr 26 22:13:15 2016
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

	Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("main"));

	LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("This is")
			<< LOG4CPLUS_TEXT(" a real")
			<< LOG4CPLUS_TEXT(" long message.") << std::endl
			<< LOG4CPLUS_TEXT("Just testing it out") << std::endl
			<< LOG4CPLUS_TEXT("What do you think?"));

	LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("This is a bool:") << true);

	return 0;
}

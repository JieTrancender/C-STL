/*************************************************************************
    > File Name: demo_first.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May  9 18:47:57 2016
 ************************************************************************/
#include <iostream>
#include <unistd.h>
#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/configurator.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>
#include <string>

using namespace log4cplus;
using namespace log4cplus::helpers;

int main(int argc, char** argv)
{
	SharedObjectPtr<Appender> _appender(new ConsoleAppender());
	_appender->setName("appender for test");

	std::string pattern = "%d{%m/%d/%y %H:%M:%S} - %m[%l]%n";
	std::auto_ptr<Layout> _layout(new PatternLayout(pattern));

	_appender->setLayout(_layout);

	Logger _logger = Logger::getInstance("test");

	_logger.addAppender(_appender);
	//_logger.setLogLevel(ALL_LOG_LEVEL);
	//
	LOG4CPLUS_DEBUG(_logger, "This is the first log message..");
	sleep(3);
	LOG4CPLUS_WARN(_logger, "This is the second log message...");
	return 0;
}

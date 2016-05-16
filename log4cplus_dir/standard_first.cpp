/*************************************************************************
    > File Name: standard_first.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May  9 21:46:32 2016
 ************************************************************************/
#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/configurator.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>

using namespace log4cplus;
using namespace log4cplus::helpers;

int main(int argc, char** argv)
{
	SharedAppenderPtr _append(new ConsoleAppender());
	_append->setName("append test");

	Logger _logger = Logger::getInstance("test");

	_logger.addAppender(_append);

	LOG4CPLUS_DEBUG(_logger, "This is the first log message.");

	return 0;
}

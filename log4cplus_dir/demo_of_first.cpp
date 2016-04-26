/*************************************************************************
    > File Name: demo_of_first.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Apr 26 21:36:25 2016
 ************************************************************************/
#include <iostream>
#include <unistd.h>
#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/configurator.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>
#include <memory>

using namespace log4cplus;
using namespace log4cplus::helpers;

int main(int argc, char** argv)
{
	//step1:Instantiate an appender object
	SharedObjectPtr<Appender> _append(new ConsoleAppender());
	_append->setName("append for test");

	//step2:Instantiate a layout object
	std::string pattern = "%d{%m/%d/%y %H:%M:%S} - %m[%|]%n";
	std::auto_ptr<Layout> _layout(new PatternLayout(pattern));

	//step3:Attach the layout object to the appender
	_append->setLayout(_layout);

	//step4:Instantiate a logger object
	Logger _logger = Logger::getInstance("test");

	//step5:Attach the appender object to the logger
	_logger.addAppender(_append);

	//step6:_logger.setLogLevel(ALL_LOG_LEVEL);
	
	LOG4CPLUS_DEBUG(_logger, "This is the first log message...");
	sleep(1);
	LOG4CPLUS_WARN(_logger, "This is the second log message...");
	return 0;
}

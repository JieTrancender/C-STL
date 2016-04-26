/*************************************************************************
    > File Name: demo_of_fourth.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Tue Apr 26 22:42:12 2016
 ************************************************************************/

#include <iostream>
#include <log4cplus/logger.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/loggingmacros.h>

using namespace log4cplus;

int main(int argc, char** argv)
{
	SharedAppenderPtr _append(new FileAppender(LOG4CPLUS_TEXT("Test.log")));
	_append->setName(LOG4CPLUS_TEXT("file log test"));

	Logger _logger = Logger::getInstance(LOG4CPLUS_TEXT("test.subtestof_filelog"));

	_logger.addAppender(_append);

	for (int i = 0; i < 10; ++i)
	{
		LOG4CPLUS_DEBUG(_logger, LOG4CPLUS_TEXT("Entering loop # End line #")
			<< i
			<< LOG4CPLUS_TEXT(" End line #"));
	}
	return 0;
}

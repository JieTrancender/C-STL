/*************************************************************************
    > File Name: standard_client.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May  9 22:40:48 2016
 ************************************************************************/
#include <log4cplus/logger.h>
#include <log4cplus/socketappender.h>
#include <log4cplus/loglevel.h>
#include <log4cplus/tstring.h>
#include <log4cplus/loggingmacros.h>
//#include <log4cplus/helpers/threads.h>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace log4cplus;

int main(int argc, char** argv)
{
//	log4cplus::helpers::sleep(1);
	tstring server_name = (argc > 1 ? LOG4CPLUS_C_STR_TO_TSTRING(argv[1]) : tstring());

	tstring host = LOG4CPLUS_TEXT("127.0.0.1");
	SharedAppenderPtr append_1(new SocketAppender(host, 9998, server_name));
	append_1->setName(LOG4CPLUS_TEXT("First"));
	Logger::getRoot().addAppender(append_1);

	Logger root = Logger::getRoot();
	Logger test = Logger::getInstance(LOG4CPLUS_TEXT("socket.test"));

	LOG4CPLUS_DEBUG(root, LOG4CPLUS_TEXT("This is")
			<< LOG4CPLUS_TEXT(" a real")
			<< LOG4CPLUS_TEXT("ly long message.") << endl
			<< LOG4CPLUS_TEXT("Just testing it out") << endl
			<<LOG4CPLUS_TEXT("What do you think?"));
	test.setLogLevel(NOT_SET_LOG_LEVEL);
	LOG4CPLUS_DEBUG(test, "This is a bool:" << true);
	LOG4CPLUS_INFO(test, "This is a char:" << 'x');
	LOG4CPLUS_INFO(test, "This is a short:" << ((short)-100));

	return 0;
}

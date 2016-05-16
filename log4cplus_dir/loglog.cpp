/*************************************************************************
    > File Name: loglog.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May  9 21:53:07 2016
 ************************************************************************/
#include <iostream>
#include <log4cplus/helpers/loglog.h>

using namespace log4cplus::helpers;

void printMsgs()
{
	std::cout << "Entering printMsgs()..." << std::endl;
	LogLog::getLogLog()->debug("This is a debug statement...");
	LogLog::getLogLog()->warn("This is a warning...");
	LogLog::getLogLog()->error("This is a error...");
	std::cout << "Exiting printMsgs()..." << std::endl;
}

int main(int argc, char** argv)
{
	printMsgs();

	std::cout << "Turning on debug..." << std::endl;
	LogLog::getLogLog()->setInternalDebugging(true);
	printMsgs();

	std::cout << "Turning on quiet mode..." << std::endl;
	LogLog::getLogLog()->setQuietMode(true);
	printMsgs();

	return 0;
}

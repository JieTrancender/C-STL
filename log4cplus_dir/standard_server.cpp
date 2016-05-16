/*************************************************************************
    > File Name: standard_server.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May  9 22:25:05 2016
 ************************************************************************/
//#include <log4cplus/config.h>
#include <log4cplus/configurator.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/socketappender.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/socket.h>
//#include <log4cplus/helpers/threads.h>
#include <log4cplus/spi/loggerimpl.h>
#include <log4cplus/spi/loggingevent.h>
#include <iostream>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;
using namespace log4cplus::thread;

namespace ls	//ls stand for logging server
{
	class ClientThread : public AbstractThread
	{
	public:
		ClientThread(Socket client_sock):m_client_sock(client_sock)
		{
			cout << "Received a client connection!!!" << endl;
		}

		~ClientThread()
		{
			cout << "Client connection closed." << endl;
		}

		virtual void run();
		
	private:
		Socket m_client_sock;
	};

	void ClientThread::run()
	{
		while(true)
		{
			if (!m_client_sock.isOpen())
			{
				return;
			}

			SocketBuffer msg_size_buffer(sizeof(unsigned int));
			if (!m_client_sock.read(msg_size_buffer))
			{
				return;
			}
		
			unsigned int msg_size = msg_size_buffer.readInt();

			SocketBuffer buffer(msg_size);
			if (!m_client_sock.read(buffer))
			{
				return;
			}

			spi::InternalLoggingEvent event = readFromBuffer(buffer);
			Logger logger = Logger::getInstance(event.getLoggerName());
			logger.callAppenders(event);
		}
	}
}

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		cout << "Usage: port config_file" << endl;
		return 1;
	}

	int port = atoi(argv[1]);
	tstring config_file = LOG4CPLUS_C_STR_TO_TSTRING(argv[2]);

	PropertyConfigurator config(config_file);
	config.configure();

	ServerSocket server_socket(port);
	while(true)
	{
		ls::ClientThread *thread = new ls::ClientThread(server_socket.accept());
		thread->start();
	}

	return 0;
}

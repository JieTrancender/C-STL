/*************************************************************************
    > File Name: server_first.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: 2016年03月22日 星期二 13时55分00秒
 ************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>

const int c_port = 1234;
const int c_back_log = 1;

int main(int argc, char** argv)
{
	int listenfd, connectfd;
	struct sockaddr_in server;
	struct sockaddr_in client;
	
	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Failed to create socket.");
		exit(1);
	}

	int opt = SO_REUSEADDR;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(c_port);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(listenfd, (struct sockaddr*)&server, sizeof(struct sockaddr)) == -1)
	{
		perror("Failed to bind.");
		exit(1);
	}

	if(listen(listenfd, c_back_log) == -1)
	{
		perror("Failed to listen.");
		exit(1);
	}

	socklen_t sin_size = sizeof(struct sockaddr_in);
	if((connectfd = accept(listenfd, (struct sockaddr*)&client, &sin_size)) == -1)
	{
		perror("Failed to accept.");
		exit(1);
	}

	printf("You got a connection from %s.\n", inet_ntoa(client.sin_addr));
	send(connectfd, "Welcome to my server.\n", 22, 0);
	close(connectfd);
	close(listenfd);
	return 0;
}

/*************************************************************************
    > File Name: client_first.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: 2016年03月22日 星期二 14时10分58秒
 ************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <unistd.h>

const int c_port = 1234;
const int c_max_data_size = 1024;

int main(int argc, char** argv)
{
	int fd, numbytes;
	char buf[c_max_data_size];
	struct hostent *he;
	struct sockaddr_in server;

	if(argc != 2)
	{
		printf("Usage: %s<IP Address>\n", argv[0]);
		exit(1);
	}

	if((he = gethostbyname(argv[1])) == nullptr)
	{
		printf("Failed to get host.\n");
		exit(1);
	}

	if((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("Failed to socket.\n");
		exit(1);
	}

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(c_port);
	server.sin_addr = *((in_addr*)he->h_addr);

	if(connect(fd, (struct sockaddr*)&server, sizeof(struct sockaddr)) == -1)
	{
		printf("Failed to connect.\n");
		exit(1);
	}

	if((numbytes = recv(fd, buf, c_max_data_size, 0)) == -1)
	{
		printf("Failed to recv.\n");
		exit(1);
	}

	buf[numbytes] = '\0';
	printf("Server Message: %s\n", buf);
	close(fd);
	return 0;
}

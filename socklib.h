#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<time.h>
#include<string.h>

#define HOSTLEN 256
#define BACKLOG 1

int make_server_socket_q(int portnum,int backlog);
int connect_to_server(char *host,int portnum);

void choice(char *str,int fd);
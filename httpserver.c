#include "socklib.h"

#define MAXLINE 1024

int main()
{
    int serversock,connsock;
    struct sockaddr_in connaddr;
    int len;
    int num = -1;
    char buf[MAXLINE];
    //backlog参数为未完成三次握手和已完成握手但没有被accept取走的套接字和的最大值
    serversock = make_server_socket_q(6666,32);
    if(serversock == -1)
    {
        perror("Create listen socket failed!!!");
        return -1;
    }
    while (1)
    {
        connsock = accept(serversock, (struct sockaddr *)&connsock, &len);
        if (connsock == -1)
        {
            perror("Accept failed!!!");
            return -1;
        }
        num = read(connsock, buf, MAXLINE);

        if (num == -1)
        {
            perror("Server read error!!!");
            return -1;
        }
        
        
        
    }
    printf("Http_Server start work!!!\n");

    return 0;
}
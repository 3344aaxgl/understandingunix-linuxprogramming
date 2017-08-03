#include "socklib.h"

int main()
{
    int serversock,connsock;
    //backlog参数为未完成三次握手和已完成握手但没有被accept取走的套接字和的最大值
    serversock = make_server_socket_q(6666,32);
    if(serversock == -1)
    {
        perror("Create listen socket failed!!!");
    }
    while(1)
    {
       connsock = accept()
    }
    printf("Http_Server start work!!!\n");

    return 0;
}
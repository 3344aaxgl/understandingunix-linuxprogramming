#include "socklib.h"


//服务器端socket
int make_server_soket(int portnum)
{
    return make_server_socket_q(portnum,BACKLOG);
}

int make_server_socket_q(int portnum,int backlog)
{
    struct sockaddr_in saddr;
    struct hostent *hp;
    char hostname[HOSTLEN];
    int sock_id;

    sock_id = socket(PF_INET,SOCK_STREAM,0);
    if(sock_id == -1)
      return -1;
    
    bzero((void*)&saddr,sizeof(saddr));
    gethostname(hostname,HOSTLEN);
    hp = gethostbyname(hostname);

    bcopy((void*)hp->h_addr,(void*)&saddr.sin_addr,hp->h_length);
    saddr.sin_family = AF_INET;
    saddr.sin_port = portnum;

    if(bind(sock_id,(struct sockaddr*)&saddr,sizeof(saddr)) !=0)
      return -1;
    
    if(listen(sock_id,backlog) != 0)
      return -1;    
    return sock_id;
}

//客户端socket
int connect_to_server(char *host,int portnum)
{
    int sock;
    struct sockaddr_in servadd;
    struct hostent *hp;

    sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock == -1)
      return -1;
    
    bzero((void *)&servadd,sizeof(servadd));
    hp = gethostbyname(host);
    if(hp == NULL)
      return -1;
    bcopy((void*)hp->h_addr,(void*)&servadd.sin_addr,hp->h_length);
    servadd.sin_family = AF_INET;
    servadd.sin_port = portnum;

    if(connect(sock,(struct sockaddr*)&servadd,sizeof(servadd)) != 0)
      return -1;
    
    return sock;
}

//请求
void choice(char *request ,int fd)
{
  
}
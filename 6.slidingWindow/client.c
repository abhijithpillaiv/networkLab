#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void main()
{
    int skt;
    char msg[100],ack[1]="1";
    struct sockaddr_in* cliaddr,seraddr;

    // socket creation
    skt=socket(AF_INET,SOCK_STREAM,0);
    seraddr.sin_family=AF_INET;
    seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
    seraddr.sin_port=htons(3330);

    connect(skt,(struct sockaddr*)&seraddr,sizeof(seraddr));

    // send and receave
    send(skt,ack,1,0);
    recv(skt,msg,sizeof(msg),0);
    printf("from server :: %s",msg);
    if (msg)
    {
        send(skt,ack,1,0);
    }
    
}
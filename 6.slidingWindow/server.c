#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void main()
{
    int skt,nsd;
    char msg[100],ack[1];
    struct sockaddr_in* cliaddr,seraddr;

    // socket creation
    skt=socket(AF_INET,SOCK_STREAM,0);
    seraddr.sin_family=AF_INET;
    seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
    seraddr.sin_port=htons(3330);

    bind(skt,(struct sockaddr*)&seraddr,sizeof(seraddr));
    listen(skt,5);

    int len = sizeof(cliaddr);
    nsd=accept(skt,(struct sockaddr*)&cliaddr,&len);

    // send and receave
    recv(skt,ack,1,0);
    printf("Type :: ");
    fgets(msg,sizeof(msg),stdin);
    len=sizeof(msg);
    msg[len-1]='\0';
    send(nsd,msg,sizeof(msg),0);

    recv(skt,ack,1,0);
    if (ack[0]='1')
    {
        printf("ack received");
    }
    
}
#include<stdio.h>
#include <sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>

void main(){
    int skt;
    char msg[100];
    struct sockaddr_in clientadd,serveraddr;

    // socket creation
    skt=socket(AF_INET,SOCK_STREAM,0);
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
    serveraddr.sin_port=htons(33341);

if (skt)
{
  // Connection establishment
    connect(skt,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    
    // Input message and clr garbages
    printf("\ntype :: ");
    fgets(msg,sizeof(msg),stdin);
    int len = strlen(msg);
    msg[len-1]='\0';
    
    // send and receive
    send(skt,msg,sizeof(msg),0);
    recv(skt,msg,sizeof(msg),0);

    printf("\n--> %s",msg);
}

  else{
    printf("socket creation error");
  }
}
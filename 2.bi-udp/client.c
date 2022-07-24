#include<stdio.h> 
#include<sys/types.h> 
#include<netinet/in.h> 
#include<string.h> 
#include<sys/socket.h> 
void main() 
{ 
int skt,len; 
char msg[30]; 
struct sockaddr_in cliaddr,servaddr;

// Create socket
skt=socket(AF_INET,SOCK_DGRAM,0); 
cliaddr.sin_family=AF_INET; 
cliaddr.sin_addr.s_addr=htonl(INADDR_ANY); 
cliaddr.sin_port=htons(25478); 

// send and receive message
printf("\nType ::");

fgets(msg,sizeof(msg),stdin); 
len=strlen(msg);
msg[len-1]='\0'; 

sendto(skt,msg,len,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr)); 
len=sizeof(servaddr);
recvfrom(skt,msg,20,0,(struct sockaddr*)&servaddr,&len); 

printf("\n--> %s",msg); 
close(skt); 
} 
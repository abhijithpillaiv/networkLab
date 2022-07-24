#include<stdio.h> 
#include<sys/types.h> 
#include<netinet/in.h> 
#include<sys/socket.h> 
#include<string.h> 
void main() 
{ 
int skt,nsd,len,len1,len2; 
char msg[30]; 

struct sockaddr_in servaddr,cliaddr; 

// Socket creation
skt=socket(AF_INET,SOCK_DGRAM,0); 
servaddr.sin_family=AF_INET; 
servaddr.sin_addr.s_addr=htonl(INADDR_ANY); 
servaddr.sin_port=htons(25478);

// bind
nsd=bind(skt,(struct sockaddr*)&servaddr,sizeof(servaddr)); 

// send and receive
len=sizeof(cliaddr); 
recvfrom(skt,msg,20,0,(struct sockaddr*)&cliaddr,&len); 
printf("\n--> %s",msg); 

printf("\nType :: "); 
fgets(msg,sizeof(msg),stdin); 
len=strlen(msg); 
msg[len-1]='\0'; 
sendto(skt,msg,len,0,(struct sockaddr*)&cliaddr,sizeof(servaddr)); 
close(skt); 
}
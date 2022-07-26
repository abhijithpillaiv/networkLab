#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

void main()
{
    int skt, nsd;
    char msg[100];
    struct sockaddr_in clientadd, serveraddr;

    // socket creation
    skt = socket(AF_INET, SOCK_STREAM, 0);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(33341);

    if (skt)
    {
        // Connection establishment in server bind
        bind(skt, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
        listen(skt, 5);
        int c_len = sizeof(clientadd);
        nsd = accept(skt, (struct sockaddr *)&clientadd, &c_len);

        // send and receive
        recv(nsd, msg, sizeof(msg), 0);
        printf("\n--> %s", msg);

        // Input message and clr garbages
        printf("\ntype :: ");
        fgets(msg, 20, stdin);
        int len = strlen(msg);
        msg[len - 1] = '\0';

        send(nsd, msg, sizeof(msg), 0);
    }
    else
    {
        printf("socket not created");
    }
}
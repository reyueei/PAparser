#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>

int main(void) {
    unsigned int port;
    char bufor[1024];
    int gniazdo, gniazdo2;
    struct sockaddr_in adr, nadawca;
    socklen_t dl;

    printf("Enter port to listen : ");
    scanf("%u", &port);
    gniazdo = socket(AF_INET, SOCK_STREAM, 0);
    adr.sin_family = AF_INET;
    adr.sin_port = htons(port);
    adr.sin_addr.s_addr = INADDR_ANY;
    if (bind(gniazdo, (struct sockaddr*) &adr, 
             sizeof(adr)) < 0) {
        printf("Bind failed.\n");
        return 1;
    }
    if (listen(gniazdo, 10) < 0) {
        printf("Listen failed.\n");
        return 1;        
    }
    printf("Waiting for connection ...\n");
    while (gniazdo2 = accept(gniazdo,
                      (struct sockaddr*) &nadawca,
                      &dl)
          ) 
    {
   //     memset(bufor, 0, 1024);
        recv(gniazdo2, bufor, 1024, 0);
        printf("message from %s: %s\n", inet_ntoa(nadawca.sin_addr), bufor);
        close(gniazdo2);
    }
    close(gniazdo);    
}
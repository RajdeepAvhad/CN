#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int main() {
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;

    char sendBuff[1024];
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    cout << "Socket created successfully\n";

    memset(&serv_addr, 0, sizeof(serv_addr));
    memset(sendBuff, 0, sizeof(sendBuff));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000);

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    if (listen(listenfd, 10) == -1) {
        cout << "Failed to listen\n";
        return -1;
    }

    while (1) {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

        strcpy(sendBuff, "Message from server");
        write(connfd, sendBuff, strlen(sendBuff));

        close(connfd);
        sleep(1);
    }

    return 0;
}


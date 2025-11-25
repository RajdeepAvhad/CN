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





/*
🔹 Code Explanation — TCP SERVER PROGRAM 🔹

1️⃣ Required header files:
   - sys/socket.h, netinet/in.h, arpa/inet.h → socket & network structures
   - unistd.h → for read/write/close functions

2️⃣ listenfd → Server socket descriptor (for listening)
   connfd → Client connection socket descriptor (after accept)

3️⃣ socket(AF_INET, SOCK_STREAM, 0)
   - Creates a TCP socket
   - AF_INET = IPv4
   - SOCK_STREAM = TCP protocol

4️⃣ memset() → Initialize structures & buffer with 0

5️⃣ Setup server address:
   serv_addr.sin_family = AF_INET;  → IPv4
   serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
     → Accept connections on any local interface
   serv_addr.sin_port = htons(5000);
     → Port number 5000

6️⃣ bind()
   Attaches socket to specified IP & port

7️⃣ listen()
   - Enables server to accept incoming connections
   - 10 → max queue length for pending connections

8️⃣ Infinite loop:
   accept()
     → Waits for client connection
     → Returns new socket connfd for communication

   strcpy(sendBuff, "Message from server");
   write(connfd, sendBuff, strlen(sendBuff));
     → Sends message to connected client

   close(connfd);
     → Closes that client connection

   sleep(1);
     → Delay before accepting next connection

9️⃣ Server continues running forever until manually stopped
*/

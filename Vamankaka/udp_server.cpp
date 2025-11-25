#include <bits/stdc++.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;

#define BUFFSIZE 255

void Die(const char* mess) {
    perror(mess);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "USAGE: " << argv[0] << " <port>\n";
        return 1;
    }

    int sock;
    struct sockaddr_in server, client;
    char buffer[BUFFSIZE];
    unsigned int clientlen, serverlen;
    int received = 0;

    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        Die("Failed to create socket");

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(atoi(argv[1]));

    serverlen = sizeof(server);
    if (bind(sock, (struct sockaddr*)&server, serverlen) < 0)
        Die("Failed to bind server socket");

    while (1) {
        clientlen = sizeof(client);
        if ((received = recvfrom(sock, buffer, BUFFSIZE, 0,
                                 (struct sockaddr*)&client, &clientlen)) < 0)
            cout << "Failed to receive message\n";

        cout << "Client connected: " << inet_ntoa(client.sin_addr) << endl;

        if (sendto(sock, buffer, received, 0,
                   (struct sockaddr*)&client, sizeof(client)) != received)
            Die("Mismatch in number of bytes");
    }
}





/*
🔹 UDP SERVER PROGRAM — Explanation 🔹

1️⃣ Command-line:
   ./server <portnumber>
   Example: ./server 5000

2️⃣ socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)
   - Creates a UDP socket
   - SOCK_DGRAM → UDP protocol
   - PF_INET → IPv4

3️⃣ Server Address Configuration:
   server.sin_family = AF_INET;        → IPv4
   server.sin_addr.s_addr = INADDR_ANY → Accept requests from any network interface
   server.sin_port = htons(port);      → Given port number (network byte order)

4️⃣ bind()
   Assigns server IP + port to the created socket
   Makes the server ready to receive messages

5️⃣ Infinite loop to serve clients:
   recvfrom()
     - Waits for a message from client
     - Also collects client address for reply
     - Message stored in 'buffer'

   inet_ntoa()
     - Displays connected client’s IP

   sendto()
     - Sends back the same message received (echo)
     - No connection required → UDP is connectionless

6️⃣ Server runs forever until manually terminated
*/

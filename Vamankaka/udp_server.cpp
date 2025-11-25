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


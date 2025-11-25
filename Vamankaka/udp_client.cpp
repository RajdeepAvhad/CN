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
    if (argc != 4) {
        cout << "USAGE: " << argv[0] << " <server_ip> <word> <port>\n";
        return 1;
    }

    int sock;
    struct sockaddr_in server, client;
    char buffer[BUFFSIZE];
    unsigned int echolen, clientlen;
    int received = 0;

    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        Die("Failed to create socket");

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[3]));

    echolen = strlen(argv[2]);

    if (sendto(sock, argv[2], echolen, 0,
               (struct sockaddr*)&server, sizeof(server)) != echolen)
        Die("Mismatch in sent bytes");

    cout << "Received: ";
    clientlen = sizeof(client);

    if ((received = recvfrom(sock, buffer, BUFFSIZE, 0,
                             (struct sockaddr*)&client, &clientlen)) != echolen)
        Die("Mismatch in received bytes");

    buffer[received] = '\0';
    cout << buffer << endl;

    close(sock);
    return 0;
}


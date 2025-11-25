#include <bits/stdc++.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int main() {
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr;

    memset(recvBuff, 0, sizeof(recvBuff));

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "Error: Could not create socket\n";
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        cout << "Error: Connect Failed\n";
        return 1;
    }

    while ((n = read(sockfd, recvBuff, sizeof(recvBuff) - 1)) > 0) {
        recvBuff[n] = 0;
        cout << recvBuff << endl;
    }

    if (n < 0)
        cout << "Read Error\n";

    return 0;
}








/*
🔹 Code Explanation — TCP Client Program 🔹

1️⃣ Header files:
   - socket, types, netinet, arpa, unistd → Used for socket & network functions
   - bits/stdc++.h → All common standard C++ libraries

2️⃣ Variables:
   - sockfd → Socket file descriptor
   - recvBuff → Buffer to store received data
   - serv_addr → Server socket address structure
   - n → Number of bytes read

3️⃣ memset(recvBuff, 0, sizeof(recvBuff));
   Initializes buffer memory with 0

4️⃣ socket(AF_INET, SOCK_STREAM, 0);
   Creates a TCP socket (SOCK_STREAM)
   AF_INET → IPv4 communication

5️⃣ Setup server details:
   serv_addr.sin_family = AF_INET;       → IPv4
   serv_addr.sin_port = htons(5000);     → Server port (host-to-network byte order)
   serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); → Localhost IP

6️⃣ connect()
   Establishes a connection with the server
   If connect fails → server not running or wrong IP/port

7️⃣ while(read(...))
   Continuously reads data coming from server
   - read() returns number of bytes received
   - recvBuff[n] = 0 ensures proper string termination
   - prints the received message

8️⃣ If read() returns negative → print error

🔚 Program ends after server closes connection
*/

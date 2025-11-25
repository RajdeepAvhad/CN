#include <bits/stdc++.h>
using namespace std;

unsigned int ipToInt(int a, int b, int c, int d) {
    return (a << 24) | (b << 16) | (c << 8) | d;
}

void printIP(unsigned int ip) {
    cout << ((ip >> 24) & 255) << "."
         << ((ip >> 16) & 255) << "."
         << ((ip >> 8) & 255) << "."
         << (ip & 255);
}

int main() {
    int a, b, c, d, prefix;

    cout << "Enter IP Address (e.g., 192.168.1.10): ";
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);

    cout << "Enter Subnet Prefix (CIDR) (e.g., 24): ";
    cin >> prefix;

    if (prefix < 0 || prefix > 32) {
        cout << "Invalid prefix!" << endl;
        return 0;
    }

    unsigned int ip = ipToInt(a, b, c, d);

    unsigned int mask = (prefix == 0) ? 0 : (0xFFFFFFFF << (32 - prefix));

    unsigned int network = ip & mask;
    unsigned int broadcast = network | (~mask);

    cout << "\n--- Subnet Details ---\n";

    cout << "Network Address   : ";
    printIP(network);
    cout << endl;

    cout << "Broadcast Address : ";
    printIP(broadcast);
    cout << endl;

    if (prefix == 32 || prefix == 31) {
        cout << "No usable hosts\n";
    } else {
        cout << "First Usable IP   : ";
        printIP(network + 1);
        cout << endl;

        cout << "Last Usable IP    : ";
        printIP(broadcast - 1);
        cout << endl;

        cout << "Number of Hosts   : "
             << (unsigned int)(pow(2, 32 - prefix) - 2)
             << endl;
    }

    cout << "Subnet Mask       : ";
    printIP(mask);
    cout << endl;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
    int frames;
    cout << "Enter number of frames to send: ";
    cin >> frames;

    srand(time(0));

    for (int i = 1; i <= frames; i++) {
        cout << "Sending Frame " << i << "...\n";
        int ack = rand() % 2;   // 1 = received, 0 = lost

        if (ack)
            cout << "ACK " << i << " received.\n";
        else {
            cout << "ACK " << i << " lost. Resending Frame " << i << "...\n";
            cout << "ACK " << i << " received.\n";
        }
    }

    return 0;
}


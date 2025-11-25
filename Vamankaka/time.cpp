#include <bits/stdc++.h>
using namespace std;

int main() {
    int frames;
    cout << "Enter number of frames to send: ";
    cin >> frames;

    srand(time(0));

    for (int i = 1; i <= frames; i++) {
        cout << "Sending Frame " << i << "\n";
        int ack = rand() % 2;

        cout << "Timer started for Frame " << i << "\n";
        for (int t = 3; t > 0; t--) {
            cout << "Time left: " << t << "\n";
            for (int d = 0; d < 100000000; d++);
        }

        if (ack) {
            cout << "ACK " << i << " received\n";
        } else {
            cout << "Timeout. No ACK for Frame " << i << "\n";
            cout << "Resending Frame " << i << "\n";

            cout << "Timer restarted\n";
            for (int t = 3; t > 0; t--) {
                cout << "Time left: " << t << "\n";
                for (int d = 0; d < 100000000; d++);
            }

            cout << "ACK " << i << " received\n";
        }
    }

    return 0;
}


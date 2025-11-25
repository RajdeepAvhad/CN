#include <bits/stdc++.h>
using namespace std;

int main() {
    int totalFrames, windowSize;
    cout << "Enter total number of frames: ";
    cin >> totalFrames;
    cout << "Enter window size: ";
    cin >> windowSize;

    srand(time(0));

    int ack[100] = {0};

    for (int i = 1; i <= totalFrames; i += windowSize) {

        cout << "\nSending window: ";
        for (int j = i; j < i + windowSize && j <= totalFrames; j++)
            cout << "F" << j << " ";
        cout << endl;

        for (int j = i; j < i + windowSize && j <= totalFrames; j++) {
            ack[j] = rand() % 2;  

            if (ack[j])
                cout << "ACK " << j << " received.\n";
            else {
                cout << "Frame " << j << " lost. Resending Frame " << j << "...\n";
                cout << "ACK " << j << " received.\n";
            }
        }
    }

    return 0;
}


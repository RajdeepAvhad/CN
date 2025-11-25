#include <bits/stdc++.h>
using namespace std;

int main() {
    int totalFrames, windowSize;
    cout << "Enter total number of frames: ";
    cin >> totalFrames;
    cout << "Enter window size: ";
    cin >> windowSize;

    srand(time(0));

    int i = 1;
    while (i <= totalFrames) {

        int sent = 0;
        cout << "\nSending frames: ";
        for (int j = i; j < i + windowSize && j <= totalFrames; j++) {
            cout << "F" << j << " ";
            sent++;
        }
        cout << endl;

        int lostAck = rand() % (sent + 1); 

        if (lostAck == sent) {
            cout << "All " << sent << " frames acknowledged.\n";
            i += sent;
        } else {
            cout << "ACK lost for Frame " << (i + lostAck)
                 << ". Resending from Frame " << (i + lostAck) << "...\n";
        }
    }

    return 0;
}


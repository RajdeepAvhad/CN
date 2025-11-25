#include <iostream>
using namespace std;

int main() {
    int d[4], h[7], r[7];
    int p1, p2, p4;

    cout << "Enter 4 data bits (d1 d2 d3 d4): ";
    for (int i = 0; i < 4; i++)
        cin >> d[i];

    // Positioning data bits
    h[2] = d[0];
    h[4] = d[1];
    h[5] = d[2];
    h[6] = d[3];

    // Parity bits
    h[0] = (h[2] ^ h[4] ^ h[6]);  
    h[1] = (h[2] ^ h[5] ^ h[6]);  
    h[3] = (h[4] ^ h[5] ^ h[6]);  

    cout << "\nGenerated Hamming Code: ";
    for (int i = 0; i < 7; i++)
        cout << h[i];
    cout << endl;

    cout << "Enter received 7 bits: ";
    for (int i = 0; i < 7; i++)
        cin >> r[i];

    // Error checking
    p1 = r[0] ^ r[2] ^ r[4] ^ r[6];
    p2 = r[1] ^ r[2] ^ r[5] ^ r[6];
    p4 = r[3] ^ r[4] ^ r[5] ^ r[6];

    int pos = p4 * 4 + p2 * 2 + p1;

    if (pos == 0)
        cout << "No Error Detected.\n";
    else {
        cout << "Error at Position: " << pos << endl;

        r[pos - 1] ^= 1; // Correcting bit

        cout << "Corrected Code: ";
        for (int i = 0; i < 7; i++)
            cout << r[i];
        cout << endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    string data, rdata;
    int rparity;
    
    cout << "Enter 8-bit data: ";
    cin >> data;

    int count1 = 0;
    for (int i = 0; i < data.length(); i++)
        if (data[i] == '1') count1++;

    int parity = count1 % 2;   // Even parity
    cout << "Generated Even Parity Bit = " << parity << endl;

    cout << "\nEnter received 8-bit data: ";
    cin >> rdata;
    cout << "Enter received parity bit: ";
    cin >> rparity;

    int check = 0;
    for (int i = 0; i < rdata.length(); i++)
        if (rdata[i] == '1') check++;

    check = check % 2;

    if (check == rparity)
        cout << "\nNo Error Detected.\n";
    else
        cout << "\nError Detected!\n";

    return 0;
}


#include <iostream>
using namespace std;

string XORfunc(string a, string b) {
    string result = "";
    for (int i = 1; i < b.length(); i++)
        result += (a[i] == b[i] ? '0' : '1');
    return result;
}

string mod2div(string data, string divisor) {
    int pick = divisor.length();
    string temp = data.substr(0, pick);

    while (pick < data.length()) {
        if (temp[0] == '1')
            temp = XORfunc(divisor, temp) + data[pick];
        else
            temp = XORfunc(string(pick, '0'), temp) + data[pick];
        pick++;
    }

    if (temp[0] == '1')
        temp = XORfunc(divisor, temp);
    else
        temp = XORfunc(string(pick, '0'), temp);

    return temp;
}

int main() {
    string data, divisor = "1101";
    cout << "Enter data bits: ";
    cin >> data;

    int r = divisor.length() - 1;
    string appended = data + string(r, '0');

    string remainder = mod2div(appended, divisor);

    cout << "CRC Remainder = " << remainder << endl;

    string codeword = data + remainder;
    cout << "Transmitted Codeword = " << codeword << endl;

    string received;
    cout << "\nEnter received codeword: ";
    cin >> received;

    string check = mod2div(received, divisor);

    if (check.find('1') != string::npos)
        cout << "Error Detected!\n";
    else
        cout << "No Error Detected.\n";

    return 0;
}


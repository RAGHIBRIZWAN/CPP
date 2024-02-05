#include <iostream>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

int LCM(int a, int b, int currentMultiple = 1) {
    if (currentMultiple % a == 0 && currentMultiple % b == 0) {
        return currentMultiple;
    } else {
        return LCM(a, b, currentMultiple + 1);
    }
}

int main() {
    int a, b;

    cout << "Enter the first number: ";
    cin >> a;

    cout << "Enter the second number: ";
    cin >> b;

    int gcd = GCD(a, b);
    cout << "GCD using Recursion: " << gcd << endl;

    int lcm = LCM(a,b);
    cout << "LCM: " << lcm << endl;
}

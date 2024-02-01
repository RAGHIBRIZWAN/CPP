#include <iostream>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

int LCM(int a, int b){
    return (a*b) / GCD(a,b);
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

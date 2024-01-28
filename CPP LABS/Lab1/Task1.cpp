#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: " << endl;
    cin >> num;

    if (num < 2) {
        cout << "Not a prime number" << endl;
        return 0;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            cout << "It is not a prime number" << endl;
            return 0;
        }
    }
    cout << "It is a prime number" << endl;

    return 0;
}

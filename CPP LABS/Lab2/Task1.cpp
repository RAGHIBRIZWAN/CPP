#include <iostream>
using namespace std;

void recursiveSwap(int &a, int &b,int ite) {

    if (ite == 0) {
        return;
    }

    a = a ^ b;

    recursiveSwap(b,a,ite-1);
}

int main() {
    int num1, num2,iterations = 3;


    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << endl;

    recursiveSwap(num1, num2,iterations);

    cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}

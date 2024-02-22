#include <iostream>
using namespace std;

class LoanHelper {
    const float interest = 0.5;
    int amount;
    int months;
    float ans = 0;

public:
    LoanHelper() {}
    LoanHelper(int amount, int months) {
        this->amount = amount;
        this->months = months;
    }
    void CalculateLoan() {
        ans = static_cast<float>(amount) * interest / months;
    }
    void display() {
        cout << "You have to pay " << ans << " every month for " << months << " months to repay your loan with an interest of " << interest << "%" << endl;
    }
};

int main() {
    LoanHelper loan(500, 12);
    loan.CalculateLoan();
    loan.display();
}

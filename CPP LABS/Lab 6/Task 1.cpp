// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class BankAccount{
    int accountId;
    double balance;
    int* transactionHistory;
    int numTransactions;
    
public:
    BankAccount(int accountId, double balance, int numTransactions) {
        this->accountId = accountId;
        this->balance = balance;
        this->numTransactions = numTransactions;
        this->transactionHistory = new int[numTransactions];
        for (int i = 0; i < numTransactions; i++) {
            transactionHistory[i] = i * 100 + 100;
        }
    }
    
   BankAccount(const BankAccount &bank) {
        this->accountId = bank.accountId;
        this->balance = bank.balance;
        this->numTransactions = bank.numTransactions;
        this->transactionHistory = new int[numTransactions];
        for (int i = 0; i < numTransactions; i++) {
            this->transactionHistory[i] = bank.transactionHistory[i];
        }
    }
    
    
    
    void display() {
        cout << "Account ID: " << accountId << endl;
        cout << "Balance: " << balance << endl;
        cout << "Number of Transactions: " << numTransactions << endl;
        cout << "Transaction History:" << endl;
        for (int i = 0; i < numTransactions; i++) {
            cout << transactionHistory[i] << endl;
        }
    }
    
    void updateTransactionHistory(int* newTransactions, int newNumTransactions) {
        delete[] transactionHistory;
        this->numTransactions = newNumTransactions;
        this->transactionHistory = new int[numTransactions];
        for (int i = 0; i < numTransactions; i++) {
            this->transactionHistory[i] = newTransactions[i];
        }
    }
    
    ~BankAccount() {
        delete[] transactionHistory;
    }
};

int main() {
    BankAccount bank1(1,1000,3);
    BankAccount bank2(bank1);
    cout<<"Display for account 1"<<endl;
    bank1.display();
    cout<<"Display for account 2"<<endl;
    bank2.display();
    cout<<"Update transaction is called"<<endl;
    int newTransactions[] = {500, 600};
    bank1.updateTransactionHistory(newTransactions, 2);
    cout<<"Display for account 1"<<endl;
    bank1.display();
    cout<<"Display for account 2"<<endl;
    bank2.display();
    return 0;
}

/*
Programmer: Raghib Rizwan Rabani
NU ID: 23K-0012
*/

#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
public:
    Account(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}
    virtual double deposit(double amount) = 0;
    virtual double withdraw(double amount) = 0;
    virtual double calculateInterest() = 0;
    int getAccountNumber() { return accountNumber; }
    double getBalance() { return balance; }
};

class SavingsAccount : public Account {
protected:
    double interestRate;
public:
    SavingsAccount(int accountNumber, double balance, double interestRate) : Account(accountNumber, balance), interestRate(interestRate) {}

    double deposit(double amount){
        balance += amount;
        return amount;
    }

    double withdraw(double amount){
        if(amount < balance){
            balance -= amount;
        }
        else{
            cout<<"Sorry Insufficient Balance!"<<endl;
        }
        return amount;
    }

    double calculateInterest(){
        double time, interest;
        cout << "Enter time period (in years): ";
        cin >> time;
        
        interest = balance * interestRate * time;
        return interest;
    }
};

class CurrentAccount : public Account {
protected:
    double overdraftLimit;
public:
    CurrentAccount(int accountNumber, double balance, double overdraftLimit) : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    double deposit(double amount){
        balance += amount;
        return amount;
    }

    double withdraw(double amount){
        if (balance - amount >= overdraftLimit) {
            balance -= amount;
            return amount;
        } else {
            cout << "Withdrawal amount exceeds overdraft limit!" << endl;
            return 0;
        }
    }

    double calculateInterest(){
        return 0;
    }
};

int main() {
    SavingsAccount savings(12345, 1000.0, 0.05);
    CurrentAccount current(54321, 500.0, 100.0);

    cout<< "Savings account Number: " <<savings.getAccountNumber()<<endl;
    cout << "Current account Number: "<< current.getAccountNumber()<<endl;

    cout << "\nInitial balances:" << endl;
    cout << "Savings account balance: " << savings.getBalance() << endl;
    cout << "Current account balance: " << current.getBalance() << endl;

    savings.deposit(500.0);
    current.withdraw(200.0);

    cout << "\nBalances after transactions:" << endl;
    cout << "Savings account balance: " << savings.getBalance() << endl;
    cout << "Current account balance: " << current.getBalance() << endl;

    cout << "\nInterest earned by savings account: " << savings.calculateInterest() << endl;

    return 0;
}

#include <iostream>
using namespace std;

class BankAccount{
    string accountNumber;
    string accountHolderName;
    int balance;
public:

    BankAccount(){};
    BankAccount(string accountNumber, string accountHolderName, int balance){
        this -> accountNumber = accountNumber;
        this -> accountHolderName = accountHolderName;
        this ->balance = balance;
    }
    void deposit(double amount){
        balance += amount;
    }
    void withdraw(double amount){
        if(amount <= balance){
            balance -= amount;
            cout<<"Sufficient amount! "<<endl;
        }
        else{
            cout<<"No sufficient amount! "<<endl;
        }
    }
    void display(){
        cout<<accountNumber<<endl;
        cout<<accountHolderName<<endl;
        cout<<balance<<endl;
    }
};

int main(){
    BankAccount bank[10];
    bank[0] = BankAccount("12345","Raghib",0);
    bank[0].display();
    bank[0].deposit(0.00);
    bank[0].withdraw(200.00);
    bank[0].display();
}

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class BankAccount{
    int accountId;
    double balance;
    int* transactionHistory;
    int numTransactions;
    
public:
    BankAccount(int accountId, double balance,int numTransactions){
        this-> transactionHistory = new int[3];
        transactionHistory[0] = 100;
         transactionHistory[1] = 200;
          transactionHistory[2] = 300;
        this-> accountId = accountId;
        this-> balance = balance;
        this-> numTransactions = numTransactions;
    }
    
    BankAccount(BankAccount &bank){
        transactionHistory = new int[3];
        accountId = bank.accountId;
        balance = bank.balance;
        numTransactions = bank.numTransactions;
    }
    
    ~BankAccount(){
        delete[] transactionHistory;
    }
    
    void display(){
        cout<<accountId<<endl;
        cout<<balance<<endl;
        cout<<numTransactions<<endl;
        for(int i = 0; i < numTransactions; i++){
            cout<<transactionHistory[i]<<endl;
        }
    }
    
    void updateTransactionHistory(int transaction){
        delete[] transactionHistory;
        transactionHistory = new int[transaction];
        cout<<"Enter the transaction you want to delete";
        for(int i = 0; i < transaction; i++){
            cout<<"Enter transaction num"<<i+1<,endl;
            cin>>
              
        }
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
    bank1.updateTransactionHistory();
    cout<<"Display for account 1"<<endl;
    bank1.display();
    cout<<"Display for account 2"<<endl;
    bank2.display();
    return 0;
}

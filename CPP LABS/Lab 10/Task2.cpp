#include<iostream>
using namespace std;

class Base{
public:
    int num;
    Base(int num):num(num){}
    Base operator--(){
        return num * 4;
    } 
    Base operator--(int){
        return num / 4;
    } 
    void display(){
        cout<<"Value is: "<<num;
    }

};

int main(){
    Base b(5);
    b = --b;
    b.display();
    cout<<endl;
    b = b--;
    b.display();
}

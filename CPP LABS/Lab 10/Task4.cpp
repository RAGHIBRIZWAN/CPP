/*
Name: Raghib Rizwan Rabani
NU ID: 23K-0012
*/
#include<iostream>
using namespace std;
class perimeter{
    int length,breadth;
    friend class printClass;
    int calculate(){
        return 2*(length-breadth);
    }
public:
    perimeter(int length,int breadth):length(length),breadth(breadth){}
};
class printClass{
public:
    void display(perimeter &per){
        cout<<"Perimeter is: "<<per.calculate();
    }
};

int main(){
    perimeter per(10,5);
    printClass print;
    print.display(per);
}

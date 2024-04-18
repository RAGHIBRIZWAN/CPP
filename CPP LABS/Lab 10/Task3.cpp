/*
Name: Raghib Rizwan Rabani
NU ID: 23K-0012
*/
#include<iostream>
using namespace std;

class shape{
    int area;
public:
    shape(int area):area(area){}

    shape operator+ (shape &obj){
        return area + obj.area;
    }
    void display(){
        cout<<"Area will be: "<<area;
    }
};

int main(){
    shape shape1(3),shape2(2);
    shape ans = shape1 + shape2;
    ans.display();
}

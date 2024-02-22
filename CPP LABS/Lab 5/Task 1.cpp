/*
Programmer: Raghib Rizwan Rabani
NU_ID: 23K-0012
Date: 22/2/2024
*/

#include <iostream>
using namespace std;

class Length{
    float sideLength;
    float area;
    static float allAreas;
    
public:
    Length(){};
    Length(float sideLength){
        this -> sideLength = sideLength;
    }
    void calculateArea(){
        area = sideLength * sideLength;
        allAreas += area;
    }
    void setdata(float sideLength){
        this -> sideLength = sideLength;
    }
    void getdata(){
        cout << "Side Length: " << sideLength << endl;
        cout << "Area: " << area << endl;
        cout << "Total Area: " << allAreas << endl;
    }
};

float Length::allAreas = 0;

int main() {
    Length side;
    side = Length(5);
    side.calculateArea();
    side.getdata();
    side = Length(10);
    side.calculateArea();
    side.getdata();
    return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
double pi = 3.142;

class Shape{
public:
    virtual double area() const{
        return 0;
    }
    virtual double perimeter() const{
        return 0;
    }
    virtual void displayProperties() const{
    }

};
class Circle:public Shape{
    double r;
public:
    // Circle(double r){
    //     this->r = r;
    // }
    double area(){
        cout<<"Enter the value of the radius: "<<endl;
        cin>>this->r;
        cout<<"The area of triangle is: ";
        return pi*r*r;
    }
    double perimeter(){
        cout<<"The perimeter of triangle is: ";
        return 2*pi*r;
    }
    void displayProperties(){
        cout<<"AREA: "<<area()<<endl;
        cout<<"PERIMETER: "<<perimeter()<<endl;
        cout<<"DIAMETER: "<< r*2;
    }

};
class Rectangle:public Shape{
    double L;
    double W;
public:
     double area(){
        cout<<"Enter the value of the length: "<<endl;
        cin>>this->L;
        cout<<"Enter the value of the width: "<<endl;
        cin>>this->W;
        cout<<"The area of rectangle is: ";
        return L*W;
    }
    double perimeter(){
        cout<<"The perimeter of rectangle is: ";
        return 2*(L+W);
    }
    void displayProperties(){
        cout<<"AREA: "<<area()<<endl;
        cout<<"PERIMETER: "<<perimeter()<<endl;
        cout<<"DIAGONAL: "<<sqrt((L*L)+(W*W));
    }
};
class Square:public Shape{
    double L;
public:
     double area(){
        cout<<"Enter the value of the length: "<<endl;
        cin>>this->L;
        cout<<"The area of rectangle is: ";
        return L*L;
    }
    double perimeter(){
        cout<<"The perimeter of square is: ";
        return 4*(L);
    }
    void displayProperties(){
        cout<<"AREA: "<<area()<<endl;
        cout<<"PERIMETER: "<<perimeter()<<endl;
        cout<<"DIAGONAL: "<<sqrt(2)*L;
    }
};
class Triangle:public Shape{
protected:
    double B;
    double H;
    double S;
public:
    double perimeter(){
        cout<<"The perimeter of rectangle is: ";
        return B + H + S;
    }
    double area(){
        cout<<"Enter the value of the base: "<<endl;
        cin>>this->B;
        cout<<"Enter the value of the height: "<<endl;
        cin>>this->H;
         cout<<"Enter the value of the side: "<<endl;
        cin>>this->S;
        cout<<"The area of triangle is: ";
        return sqrt(perimeter()*(perimeter()-B)*(perimeter()-H)*(perimeter()-S));
    }
    void displayProperties(){
        cout<<"AREA: "<<area()<<endl;
        cout<<"PERIMETER: "<<perimeter()<<endl; 
    }
};
class Equilateraltriangle:public Triangle{
     double area(){
        cout<<"Enter the value of the height: "<<endl;
        cout<<"The area of triangle is: ";
        return B*B*B;
    }
    void displayProperties(){
        cout<<"AREA: "<<area()<<endl;
    }
} ;

int main(){
    Shape *shp;
    Circle cir;
    shp = &cir;
    shp->area();
    shp->perimeter();
    shp->displayProperties();
    cout<<endl;
    Square sqr;
    shp = &sqr;
    shp->area();
    shp->perimeter();
    shp->displayProperties();
    cout<<endl;
    Rectangle rec;
    shp = &rec;
    shp->area();
    shp->perimeter();
    shp->displayProperties();
    cout<<endl;
    Triangle tri;
    shp = &tri;
    shp->area();
    shp->perimeter();
    shp->displayProperties();
    cout<<endl;
    Equilateraltriangle equ;
    shp = &equ;
    shp->area();
    shp->perimeter();
    shp->displayProperties();
}

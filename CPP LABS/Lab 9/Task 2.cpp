#include<iostream>
#include<cmath>
using namespace std;
double pi = 3.142;

class Shape{
public:
    Shape(){}
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
    Circle(){}
    Circle(double r):r(r){}
    double area(){
        cout<<"The area of circle is: ";
        return pi*r*r;
    }
    double perimeter(){
        cout<<"The perimeter of circle is: ";
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
    Rectangle(){}
    Rectangle(double L,double W):L(L),W(W){}
    double area(){
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
    Square(){}
    Square(double L):L(L){}
    double area(){
        cout<<"The area of square is: ";
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
    Triangle(){}
    Triangle(double B,double H,double S):B(B),H(H),S(S){}
    double perimeter(){
        cout<<"The perimeter of rectangle is: ";
        return B + H + S;
    }
    double area(){
        cout<<"The area of triangle is: ";
        return sqrt(perimeter()*(perimeter()-B)*(perimeter()-H)*(perimeter()-S));
    }
    void displayProperties(){
        cout<<"AREA: "<<area()<<endl;
        cout<<"PERIMETER: "<<perimeter()<<endl; 
    }
};
class Equilateraltriangle:public Triangle{
public:
    Equilateraltriangle(){}
    Equilateraltriangle(double B):Triangle(B,B,B){}
    double area(){
        cout<<"The area of equilateral triangle is: ";
        return B * B * B;
    }
    void displayProperties(){
        cout<<"AREA: "<<area()<<endl;
    }
};

int main(){
    int choice;
    cout<<"Welcome to the Geometry Competition Calculator! "<<endl;
    cout<<endl;
    Shape *shp;
    do{
        cout<<"Please select a shape: "<<endl;
        cout<<"1.Circle\n2.Rectangle\n3.Square\n4.Triangle\n5.Equilateral Triangle\n6.Exit"<<endl;
        cin>>choice;
        switch (choice){
            case 1:{
                double radius = 5.0;
                Circle cir(radius);
                shp = &cir;
                shp->area();
                shp->perimeter();
                shp->displayProperties(); 
                break;
            }
            case 2:{
                double L=4.0,W=5.0;
                Rectangle rec(L,W);
                shp = &rec;
                shp->area();
                shp->perimeter();
                shp->displayProperties(); 
                break;
            }
            case 3:{
                double L=4.0;
                Square sqr(L);
                shp = &sqr;
                shp->area();
                shp->perimeter();
                shp->displayProperties(); 
                break;
            }
            case 4:{
                double B = 4.0, H = 5.0, S = 3.0;
                Triangle tri(B,H,S);
                shp = &tri;
                shp->area();
                shp->perimeter();
                shp->displayProperties(); 
                break;
            }
            case 5:{
                double B = 4.0;
                Equilateraltriangle equi(B);
                shp = &equi;
                shp->area();
                shp->perimeter();
                shp->displayProperties(); 
                break;
            }
            case 6:
                return 0;
            default:
                break;
        }
        string cont;
        cout<<"Do you want to continue? (yes/no) ";
        cin>>cont;
        if (cont != "yes"){
            return 0;
        }
    }while(1);
}

#include <iostream>
using namespace std;

const double PI = 3.142;

class Shape {
public:
    // Calculate the area of a circle given its radius
    double area(double radius) const {
        return PI * radius * radius;
    }

    // Calculate the area of a rectangle given its length and width
    int area(int length, int width) const {
        return length * width;
    }

    // Calculate the area of a triangle given its base and height
    double area(double base, double height) const {
        return 0.5 * base * height;
    }

    // Calculate the perimeter of a circle given its radius
    double perimeter(double radius) const {
        return 2 * PI * radius;
    }

    // Calculate the perimeter of a rectangle given its length and width
    double perimeter(double length, double width) const {
        return 2 * (length + width);
    }

    // Calculate the perimeter of a triangle given its three sides
    double perimeter(double side1,double side2,double side3) const {
        return side1 + side2 + side3;
    }
};

int main() {
    Shape shape;

    // Circle
    double circleRadius = 5.0;
    cout << "Radius of Circle: " << circleRadius << endl;
    cout << "Area: " << shape.area(circleRadius) << endl;
    cout << "Perimeter: " << shape.perimeter(circleRadius) << endl;

    // Rectangle
    int rectangleLength = 6;
    int rectangleWidth = 4;
    cout << "Length of Rectangle: " << rectangleLength << ", Width of Rectangle: " << rectangleWidth << endl;
    cout << "Area: " << shape.area(rectangleLength, rectangleWidth) << endl;
    cout << "Perimeter: " << shape.perimeter(rectangleLength, rectangleWidth) << endl;

    // Triangle
    double triangleBase = 7.0;
    double triangleHeight = 3.0;
    double triangleSide1 = 5.0;
    double triangleSide2 = 6.0;
    cout << "Base of triangle " << triangleBase << ", Height of triangle: " << triangleHeight << endl;
    cout << "Area: " << shape.area(triangleBase, triangleHeight) << endl;
    cout << "Perimeter: " << shape.perimeter(triangleSide1, triangleSide2, triangleBase) << endl;

    return 0;
}

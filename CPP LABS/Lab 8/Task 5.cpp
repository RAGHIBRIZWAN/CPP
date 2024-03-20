#include<iostream>
using namespace std;

class Vehicle {
protected:
    string make;
    int model;
    int year;

public:
    Vehicle(const string& make, int model, int year): make(make), model(model), year(year) {}
    void display(){
        cout<<"Make: "<<make<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Year: "<<year<<endl;
    }
};

class Car : public Vehicle {
protected:
    int doors;
    int fuelEfficiency;

public:
    Car(const string& make, int model, int year, int doors, int fuelEfficiency): Vehicle(make, model, year), doors(doors), fuelEfficiency(fuelEfficiency) {}

    void display(){
        Vehicle::display();
        cout<<"Doors: "<<doors<<endl;
        cout<<"Fuel Efficiency: "<<fuelEfficiency<<endl;
    }
};

class ElectricCar : public Car {
protected:
    int batteryLife;

public:
    ElectricCar(const string& make, int model, int year, int doors, int fuelEfficiency, int batteryLife): Car(make, model, year, doors, fuelEfficiency), batteryLife(batteryLife) {}

    void display(){
        Car::display();
        cout<<"Battry Life: "<<batteryLife<<endl;
    }
};

int main() {
    ElectricCar electricCar("Tesla", 2022, 4, 4, 300, 500);
    electricCar.display();

    return 0;
}

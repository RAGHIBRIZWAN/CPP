/*
Programmer: Raghib Rizwan Rabani
NU ID: 23K-0012
*/

#include<iostream>
using namespace std;

class Vehicle{
protected:
    string make, model;
    int speed;
public:
    Vehicle(string make, string model, int speed) : make(make), model(model), speed(speed) {}

    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void calculateFuelEfficiency() = 0;
    string getMake() const {
        return make;
    }
    string getModel() const {
        return model;
    }
    int getSpeed() const {
        return speed;
    }
};

class Car : public Vehicle{
protected:
    double fuelCapacity;
public:
    Car(string make, string model, int speed, double fuelCapacity) : Vehicle(make, model, speed), fuelCapacity(fuelCapacity) {}

    void accelerate(){
        cout << "Car is accelerating" << endl;
    }
    void brake(){
        cout << "Brake has been applied for car" << endl;
    }
    void calculateFuelEfficiency(){
        cout << "Calculating fuel efficiency for car" << endl;
    }
};

class Truck : public Vehicle{
protected:
    double cargoCapacity;
public:
    Truck(string make, string model, int speed, double cargoCapacity) : Vehicle(make, model, speed), cargoCapacity(cargoCapacity) {}

    void accelerate(){
        cout << "Truck is accelerating" << endl;
    }
    void brake(){
        cout << "Brake has been applied for truck" << endl;
    }
    void calculateFuelEfficiency(){
        cout << "Calculating fuel efficiency for truck" << endl;
    }
};

int main(){
    Car car("Honda", "Civic", 1600, 50.5);
    car.accelerate();
    car.brake();
    car.calculateFuelEfficiency();

    Truck truck("Bugatti", "Chiron", 2500, 1000.0);
    truck.accelerate();
    truck.brake();
    truck.calculateFuelEfficiency();

    return 0;
}

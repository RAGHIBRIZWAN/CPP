/*
Programmer: Raghib Rizwan Rabani
NU_ID: 23K-0012
Date: 22/2/2024
*/

#include<iostream>
using namespace std;

class Engine{

public:
    string type;

    Engine(string type){
        this -> type = type;
    }
};

class Wheels{

public:
    string type;

    Wheels(string type){
        this -> type = type;
    }
};

class HeadLights{

public:
    string type;

    HeadLights(string type){
        this -> type = type;
    }
};

class Steering{

public:
    string type;

    Steering(string type){
        this -> type = type;
    }
};

class Car{
    Engine *e;
    Wheels *w;
    HeadLights *h;
    Steering *s;
    string type;
    int model;

public:

    Car(Engine *e,Wheels *w,HeadLights *h,Steering *s,string type,int model){
        this -> e=e;
        this -> w=w;
        this -> h=h;
        this -> s=s;
        this -> type=type;
        this -> model=model;
    }

    void display(){
        cout<<"engine type: "<< e -> type<<endl;
        cout<<"wheel type: "<< w -> type<<endl;
        cout<<"headlights type: "<< h -> type<<endl;
        cout<<"steering type: "<< s -> type<<endl;
        cout<<"car type: "<< type<<endl;
        cout<<"car model: "<< model<<endl;
    }
};

int main(){
    Engine e1("V8");
    Wheels w1("Off-Road");
    HeadLights h1("Fog");
    Steering s1("Power");
    Car car(&e1,&w1,&h1,&s1,"Sedan",2024);
    car.display();
}

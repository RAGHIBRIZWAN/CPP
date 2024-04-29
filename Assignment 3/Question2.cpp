#include<iostream>
using namespace std;

template <typename T>
class Pet{
    string name;
    int age;
public:
    Pet(string name, int age):name(name),age(age){}

    virtual void makeSound() = 0;

    void Print(){
        cout<<name<<endl;
        cout<<age<<endl;
    }
};

class Cat : public Pet<Cat>{
public:
    Cat(string name, int age):Pet(name,age){}

    void makeSound(){
        Print();
        cout<<"Meow"<<endl;
    }
};

class Dog : public Pet<Dog>{
public:
    Dog(string name, int age):Pet(name,age){}

    void makeSound(){
        Print();
        cout<<"Woof"<<endl;
    }
};

class Bird : public Pet<Bird>{
public:
    Bird(string name, int age):Pet(name,age){}

    void makeSound(){
        Print();
        cout<<"Chirp"<<endl;
    }
};

int main(){
    Cat cat("Lulu",1);
    cat.makeSound();
    Dog dog("Tommy",2);
    dog.makeSound();
    Bird bird("Fiffy",3);
    bird.makeSound();
}

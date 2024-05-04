#include<iostream>
using namespace std;

template <typename T>
class Pet{
    T name;
    int age; // Change age to int
public:
    Pet(T name, int age):name(name),age(age){}

    virtual void makeSound() = 0;

    void Print(){
        cout<<name<<endl;
        cout<<age<<endl;
    }
};

template <typename T>
class Cat : public Pet<T>{
public:
    Cat(T name, int age):Pet<T>(name,age){}

    void makeSound(){
        cout<<"Meow"<<endl;
    }
};

template <typename T>
class Dog : public Pet<T>{
public:
    Dog(T name, int age):Pet<T>(name,age){}

    void makeSound(){
        cout<<"Woof"<<endl;
    }
};

template <typename T>
class Bird : public Pet<T>{
public:
    Bird(T name, int age):Pet<T>(name,age){}

    void makeSound(){
        cout<<"Chirp"<<endl;
    }
};

int main(){
    Pet<string>* pet;
    Cat<string> cat("Lulu",1);
    Dog<string> dog("Tommy",2);
    Bird<string> bird("Fiffy",3);
    pet = &cat;
    pet->makeSound();
    pet->Print();
    cout<<endl;
    pet = &dog;
    pet->makeSound();
    pet->Print();
    cout<<endl;
    pet = &bird;
    pet->makeSound();
    pet->Print(); 
}

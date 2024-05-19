#include <iostream>

class Base {
private:
    int data;

public:
    Base(int value) : data(value) {}
    void printData() {
        std::cout << "Data: " << data << std::endl;
    }

    Base operator+(const Base& other) const {
        return Base(data + other.data);
    }
};

int main() {
    Base obj1(10);
    Base obj2(20);
    Base result = obj1 + obj2;
    result.printData();
    return 0;
}

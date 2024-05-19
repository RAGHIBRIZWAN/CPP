#include <iostream>
#include <fstream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}
    virtual void saveToFile(const std::string& filename) const = 0;
};

class Student : public Person {
private:
    std::string university;

public:
    Student(const std::string& name, int age, const std::string& university)
        : Person(name, age), university(university) {}

    void saveToFile(const std::string& filename) const override {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "Name: " << name << std::endl;
            file << "Age: " << age << std::endl;
            file << "University: " << university << std::endl;
            file.close();
            std::cout << "Data saved to file: " << filename << std::endl;
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }
};

int main() {
    Student student("Ali", 21, "FAST NUCES");
    student.saveToFile("student.txt");
    return 0;
}

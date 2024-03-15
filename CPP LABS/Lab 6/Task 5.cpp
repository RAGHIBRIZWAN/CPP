#include<iostream>
#include<vector>
using namespace std;

class Course {
public:
    string code;
    string name;
    int creditHours;

    Course(string code, string name, int creditHours) : code(code), name(name), creditHours(creditHours) {}
};

class Student {
private:
    string id;
    string name;
    vector<Course> enrolledCourses;

public:
    Student(string id, string name) : id(id), name(name) {}

    void enroll(Course course) {
        enrolledCourses.push_back(course);
    }

    void drop(Course course) {
        for (int i = 0; i < enrolledCourses.size(); i++) {
            if (enrolledCourses[i].code == course.code) {
                enrolledCourses.erase(enrolledCourses.begin() + i);
                cout<<"Course deleted successfully"<<endl;
                break;
            }
        }
    }

    int getTotalCreditHours() {
        int totalHours = 0;
        for (int i = 0; i < enrolledCourses.size(); i++) {
            totalHours += enrolledCourses[i].creditHours;
        }
        return totalHours;
    }

    void printEnrolledCourses() {
        for (int i = 0; i < enrolledCourses.size(); i++) {
            cout << "Course Code: " << enrolledCourses[i].code << endl;
            cout << "Course Name: " << enrolledCourses[i].name << endl;
            cout << "Credit Hours: " << enrolledCourses[i].creditHours << endl;
            cout << endl;
        }
    }
};

int main() {
    Student stud("23K-0012", "Raghib");
    Course course1("CSC101", "Object Oriented Programming", 3);
    Course course2("MAT102", "Calculus II", 4);

    stud.enroll(course1);
    stud.enroll(course2);

    cout << "Total Credit Hours: " << stud.getTotalCreditHours() << endl;

    cout << "Enrolled Courses:" << endl;
    stud.printEnrolledCourses();

    stud.drop(course1);

    cout << "Total Credit Hours after dropping a course: " << stud.getTotalCreditHours() << endl;

    return 0;
}

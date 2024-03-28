#include<iostream>
using namespace std;

class Employee{
protected:
    int employeeID;
    string employeeName;
public:
    Employee(int employeeID,string employeeName){
        this->employeeID = employeeID;
        this->employeeName = employeeName;
    }
    virtual double calculatePay() const{

    }
    virtual void displayDetails() const{

    }
};
class FullTimeEmployee:public Employee{
    double monthlySalary;
public:
    FullTimeEmployee(double monthlySalary,int employeeID,string employeeName):Employee(employeeID,employeeName){
        this->monthlySalary = monthlySalary;
    }
    virtual double calculatePay() const{
        return monthlySalary;
    }
    virtual void displayDetails() const{
        cout<<"Employee ID: "<<employeeID<<endl;
        cout<<"Employee Name: "<<employeeName<<endl;
        cout<<"Monthly Salary: "<<monthlySalary<<endl;
    }
};
class PartTimeEmployee:public Employee{
    double hourlyWage;
    int hours;
public:
    PartTimeEmployee(double hourlyWage,int hours,int employeeID,string employeeName):Employee(employeeID,employeeName){
        this->hourlyWage = hourlyWage;
        this->hours = hours;
    }
    virtual double calculatePay() const{
        return hourlyWage*hours;
    }
    virtual void displayDetails() const{
        cout<<"Employee ID: "<<employeeID<<endl;
        cout<<"Employee Name: "<<employeeName<<endl;
        cout<<"Hourly Wage: "<<hourlyWage<<endl;
        cout<<"Hours: "<<hours<<endl;
    }
};
int main() {
    FullTimeEmployee full(10000.0, 123, "Raghib");
    PartTimeEmployee part(500, 10, 123, "Raghib");

    cout << "Full Time Employee Details:" << endl;
    full.displayDetails();

    cout << "\nPart Time Employee Details:" << endl;
    part.displayDetails();
  
    Employee* emp1 = &full;
    Employee* emp2 = &part;

    cout << "\nUsing Base Class Pointer:" << endl;
    cout << "Full Time Employee - Calculated Pay: " << emp1->calculatePay() << endl;
    cout << "Part Time Employee - Calculated Pay: " << emp2->calculatePay() << endl;

    return 0;
}

#include <iostream>
using namespace std;

struct Register{
    int Course_Id;
    string Course_Name;
};

struct Student: Register
{

    int Student_Id;
    string First_Name;
    string Last_Name;
    int Cell_No;
    string Email; 
};

int main(){
    Student stud[5];

    for (int i = 0; i < 5; i++)
    {
        cout<<"Inputs of student "<<i+1<<endl;
        cout<<"Enter your Course ID: "<<endl;
        cin>>stud[i].Course_Id; 
        cout<<"Enter your Course Name: "<<endl;
        cin>>stud[i].Course_Name; 
        cout<<"Enter your Student ID: "<<endl;
        cin>>stud[i].Student_Id; 
        cout<<"Enter your First Name: "<<endl;
        cin>>stud[i].First_Name; 
        cout<<"Enter your Last Name: "<<endl;
        cin>>stud[i].Last_Name; 
        cout<<"Enter your Cell No: "<<endl;
        cin>>stud[i].Cell_No; 
        cout<<"Enter your Email: "<<endl;
        cin>>stud[i].Email; 
    }

    for (int i = 0; i < 5; i++)
    {
        cout<<"Details of student "<<i+1<<endl;
        cout<<"Your Course Id is: "<<stud[i].Course_Id<<endl;
        cout<<"Your Course Name is: "<<stud[i].Course_Name<<endl;
        cout<<"Your Student Id is: "<<stud[i].Student_Id<<endl;
        cout<<"Your First Name is: "<<stud[i].First_Name<<endl;
        cout<<"Your Last Name is: "<<stud[i].Last_Name<<endl;
        cout<<"Your Cell Number is: "<<stud[i].Cell_No<<endl;
        cout<<"Your Email is: "<<stud[i].Email<<endl;
    }
    
    
}
